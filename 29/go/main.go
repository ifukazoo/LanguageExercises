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

func showErrorMsg() {
	fmt.Printf("Sorry. That's not a valid input.\n")
}

func main() {
	for {
		input := eInput("What is the rate of return? ")
		rate, err := strconv.Atoi(input)
		if err != nil || rate == 0 {
			showErrorMsg()
			continue
		}
		years := 72 / rate
		fmt.Printf("It will take %d years to double your initial investment.\n", years)
		break
	}
}
