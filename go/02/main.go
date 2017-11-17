package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	fmt.Print("What is the input string? ")
	scanner.Scan()
	if err := scanner.Err(); err == nil {
		text := scanner.Text()
		fmt.Println(text + " has " + strconv.Itoa(len(text)) + " characters.")
	}
}
