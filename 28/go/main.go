package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var scanner *bufio.Scanner

func init() {
	scanner = bufio.NewScanner(os.Stdin)
}

func eInput(msg string) string {
	fmt.Printf(msg)
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	return scanner.Text()
}

func main() {
	total := 0
	for i := 0; i < 5; i++ {
		input := eInput("Enter a number: ")
		num, err := strconv.Atoi(input)
		if err != nil {
			os.Exit(1)
		}
		total += num
	}
	fmt.Printf("The total is %d.\n", total)
}
