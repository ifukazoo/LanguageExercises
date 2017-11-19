package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {

	scanner := bufio.NewScanner(os.Stdin)

	fmt.Print("What is the first number? ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	firstNumber, err := strconv.Atoi(scanner.Text())
	if err != nil {
		os.Exit(1)
	}

	fmt.Print("What is the second number? ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	secondNumber, err := strconv.Atoi(scanner.Text())
	if err != nil {
		os.Exit(1)
	}

	fmt.Printf("%d + %d = %d\n", firstNumber, secondNumber, firstNumber+secondNumber)
	fmt.Printf("%d - %d = %d\n", firstNumber, secondNumber, firstNumber-secondNumber)
	fmt.Printf("%d * %d = %d\n", firstNumber, secondNumber, firstNumber*secondNumber)
	fmt.Printf("%d / %d = %d\n", firstNumber, secondNumber, firstNumber/secondNumber)
}
