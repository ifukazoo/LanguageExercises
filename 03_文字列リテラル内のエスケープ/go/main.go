package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {

	theQuote := `These aren't the droids you're looking for.`
	fmt.Print("Who said it? ")
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	if err := scanner.Err(); err == nil {
		author := scanner.Text()
		fmt.Println(author + ` says, "` + theQuote + `"`)
	}
}
