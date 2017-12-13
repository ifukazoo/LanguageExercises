package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func isAnagram(a, b string) bool {
	if len(a) != len(b) {
		return false
	}
	for _, r := range b {
		if !strings.ContainsRune(a, r) {
			return false
		}
	}
	return true
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	fmt.Println("Enter two strings and I'll tell you if then are anagrams: ")

	fmt.Print("Enter the first string: ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	first := scanner.Text()

	fmt.Print("Enter the second string: ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	second := scanner.Text()

	ok := isAnagram(first, second)

	not := ""
	if !ok {
		not = "not "
	}
	fmt.Printf("\"%s\" and \"%s\" are %sanagrams.\n", first, second, not)
}
