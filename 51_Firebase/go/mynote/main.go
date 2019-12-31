package main

import (
	"context"
	"flag"
	"fmt"
	"log"
	"os"
	"strings"
	"time"

	"cloud.google.com/go/firestore"
	firebase "firebase.google.com/go"
	"google.golang.org/api/iterator"
)

func initFirebase(ctx context.Context) *firestore.Client {
	// export GOOGLE_APPLICATION_CREDENTIALS="/path/to/service-account-file.json"
	// デフォルト認証情報を使用する
	app, err := firebase.NewApp(ctx, nil)
	if err != nil {
		log.Fatalln(err)
	}
	client, err := app.Firestore(ctx)
	if err != nil {
		log.Fatalln(err)
	}
	return client
}

func init() {
	flag.Usage = func() {
		fmt.Fprintf(os.Stderr, "Usage: %s <new note...>|<show>\n", os.Args[0])
		flag.PrintDefaults()
	}
}
func main() {
	flag.Parse()
	if flag.NArg() < 1 {
		flag.Usage()
		os.Exit(1)
	}
	cmd := strings.TrimSpace(os.Args[1])
	if !((cmd == "new" && flag.NArg() >= 2) || cmd == "show") {
		flag.Usage()
		os.Exit(1)
	}

	// 空のContext
	ctx := context.Background()
	client := initFirebase(ctx)
	defer client.Close()
	if cmd == "new" {
		_, _, err := client.Collection("notes").Add(ctx, map[string]interface{}{
			"text":    strings.Join(os.Args[2:], " "),
			"created": time.Now().UnixNano(),
		})
		if err != nil {
			log.Fatalln(err)
		}
		fmt.Println("Your note was saved.")
	} else if cmd == "show" {
		q := client.Collection("notes").OrderBy("created", firestore.Desc)
		iter := q.Documents(ctx)
		defer iter.Stop()
		for {
			doc, err := iter.Next()
			if err == iterator.Done {
				break
			}
			if err != nil {
				log.Fatalln(err)
			}
			m := doc.Data()
			unixnano, ok := m["created"].(int64)
			if !ok {
				fmt.Fprintf(os.Stderr, `unexpected value of "created". data[%v]\n`, m)
			}
			text, ok := m["text"].(string)
			if !ok {
				fmt.Fprintf(os.Stderr, `unexpected value of "text". data[%v]\n`, m)
			}
			fmt.Println(time.Unix(0, unixnano).Format("2006-01-02"), "-", text)
		}
	}
}
