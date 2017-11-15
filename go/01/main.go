package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	fmt.Print("What is your name? ")
	scanner.Scan()
	if err := scanner.Err(); err == nil {
		fmt.Println("Hello, " + scanner.Text() + ", nice to meet you!")
	}
}
