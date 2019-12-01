package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"net/http"
	"os"
	"strings"
)

// Astronaut 宇宙飛行士
type Astronaut struct {
	Name  string `json:"name"`
	Craft string `json:"craft"`
}

// AstroInfo 宇宙飛行士情報
type AstroInfo struct {
	People  []*Astronaut `json:"people"`
	Number  int          `json:"number"`
	Message string       `json:"message"`
}

func check(err error) {
	if err != nil {
		fmt.Fprintf(os.Stderr, "failed:%s\n", err.Error())
		os.Exit(1)
	}
}
func maxNameLen(astros []*Astronaut) int {
	maxName := 0
	for _, a := range astros {
		if len(a.Name) > maxName {
			maxName = len(a.Name)
		}
	}
	return maxName
}
func dispAstros(astros []*Astronaut) {
	nameFieldLen := maxNameLen(astros)
	dispLine("Name", nameFieldLen, " Craft", 6)
	dispSeparator(nameFieldLen, 6)
	for _, a := range astros {
		dispLine(a.Name, nameFieldLen, " "+a.Craft, 6)
	}
}
func dispLine(left string, leftLen int, right string, rightLen int) {
	lfmt := fmt.Sprintf("%%-%ds", leftLen+1)
	rfmt := fmt.Sprintf("%%-%ds", rightLen)
	fmt.Printf(lfmt+"|"+rfmt+"\n", left, right)
}
func dispSeparator(leftlen, rightLen int) {
	var lsep strings.Builder
	for i := 0; i < leftlen; i++ {
		lsep.WriteRune('-')
	}
	var rsep strings.Builder
	for i := 0; i < rightLen; i++ {
		rsep.WriteRune('-')
	}
	dispLine(lsep.String(), leftlen, rsep.String(), rightLen)
}
func main() {
	res, err := http.Get("http://api.open-notify.org/astros.json")
	check(err)
	defer res.Body.Close()
	reader := bufio.NewReader(res.Body)

	var astroInfo AstroInfo
	json.NewDecoder(reader).Decode(&astroInfo)
	if astroInfo.Message == "success" {
		dispAstros(astroInfo.People)
	}
}
