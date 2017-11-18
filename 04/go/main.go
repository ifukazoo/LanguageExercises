package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {

	scanner := bufio.NewScanner(os.Stdin)

	fmt.Print("Enter a noun: ")
	scanner.Scan()
	if err := scanner.Err(); err != nil {
		os.Exit(1)
	}
	noun := scanner.Text()

	fmt.Print("Enter a verv: ")
	scanner.Scan()
	if err := scanner.Err(); err != nil {
		os.Exit(1)
	}
	verb := scanner.Text()

	fmt.Print("Enter an adjective: ")
	scanner.Scan()
	if err := scanner.Err(); err != nil {
		os.Exit(1)
	}
	adjective := scanner.Text()

	fmt.Print("Enter an adverb: ")
	scanner.Scan()
	if err := scanner.Err(); err != nil {
		os.Exit(1)
	}
	adverb := scanner.Text()

	fmt.Println("Do you " + verb + " your " + adjective + " " + noun + " " + adverb + "? That's hilarious!")
}
