package main

import (
	"bufio"
	"fmt"
	"html/template"
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
func validateYesNo(s string) (bool, string) {
	trimed := strings.TrimSpace(s)
	if len(trimed) == 0 {
		return false, ""
	}
	if strings.ToLower(trimed)[0:1] == "y" {
		return true, "y"
	}
	return true, "n"
}

func check(err error) {
	if err != nil {
		fmt.Fprintf(os.Stderr, "failed:%s\n", err.Error())
		os.Exit(1)
	}
}

func makeDirectories(path string) {
	err := os.MkdirAll(path, os.ModePerm)
	check(err)
}

func createIndexHTML(path, title, authorName string) {
	f, err := os.Create(path)
	check(err)
	defer f.Close()
	w := bufio.NewWriter(f)

	templ := `
<!DOCTYPE html>
<html>
    <head>
        <title>{{.Title}}</title>
        <meta name="author" content="{{.Author}}">
    </head>
</html>
`
	t, err := template.New("exercise").Parse(templ)
	check(err)
	data := struct {
		Title  string
		Author string
	}{
		Title:  title,
		Author: authorName,
	}
	t.Execute(w, data)
	w.Flush()
}

func main() {
	wrongInputMsg := "Sorry. That's not a valid input."

	siteName := readUserInputWithValidator("Site name: ", validateNotEmpty, wrongInputMsg)

	authorName := readUserInputWithValidator("Author: ", validateNotEmpty, wrongInputMsg)

	hasJs := readUserInputWithValidator("Do you want a folder fo JavaScript? ", validateYesNo, wrongInputMsg) == "y"

	hasCSS := readUserInputWithValidator("Do you want a folder fo CSS? ", validateYesNo, wrongInputMsg) == "y"

	siteDirPath := "./" + siteName
	makeDirectories(siteDirPath)
	fmt.Printf("Created %s\n", siteDirPath)

	indexPath := siteDirPath + "/index.html"
	createIndexHTML(indexPath, siteName, authorName)
	fmt.Printf("Created %s\n", indexPath)
	if hasJs {
		siteJsDirPath := siteDirPath + "/js"
		makeDirectories(siteJsDirPath)
		fmt.Printf("Created %s\n", siteJsDirPath)
	}
	if hasCSS {
		siteCSSDirPath := siteDirPath + "/css"
		makeDirectories(siteCSSDirPath)
		fmt.Printf("Created %s\n", siteCSSDirPath)
	}
}
