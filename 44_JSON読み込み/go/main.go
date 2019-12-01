package main

import (
	"bufio"
	"flag"
	"fmt"
	"os"
	"strings"
)

func validateNotEmpty(s string) (bool, string) {
	trimed := strings.TrimSpace(s)
	if len(trimed) == 0 {
		return false, ""
	}
	return true, trimed
}

func check(err error) {
	if err != nil {
		fmt.Fprintf(os.Stderr, "failed:%s\n", err.Error())
		os.Exit(1)
	}
}

func init() {
	flag.Usage = func() {
		fmt.Fprintf(os.Stderr, "Usage: %s <json file>\n", os.Args[0])
		flag.PrintDefaults()
	}
}

func main() {

	flag.Parse()
	if flag.NArg() < 1 {
		flag.Usage()
		os.Exit(1)
	}

	f, err := os.Open(flag.Arg(0))
	check(err)
	defer f.Close()

	products, err := parse(bufio.NewReader(f))
	check(err)

	invalidMsg := "Sorry, that product was not found in our inventory."
	for {
		name := readUserInputWithValidator("What is the procuct name? ", validateNotEmpty, invalidMsg)
		for _, p := range products.Products {
			if p.Name == name {
				p.disp()
				goto found
			}
		}
		fmt.Println(invalidMsg)
	}
found:
}
