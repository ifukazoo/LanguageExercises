package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {

	scanner := bufio.NewScanner(os.Stdin)

	fmt.Print("Enter the first number: ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	firstNumber, err := strconv.Atoi(scanner.Text())
	if err != nil {
		os.Exit(1)
	}

	fmt.Print("Enter the second number: ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	secondNumber, err := strconv.Atoi(scanner.Text())
	if err != nil {
		os.Exit(1)
	}

	fmt.Print("Enter the third number: ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	thirdNumber, err := strconv.Atoi(scanner.Text())
	if err != nil {
		os.Exit(1)
	}
	if (firstNumber == secondNumber) || (firstNumber == thirdNumber) || (secondNumber == thirdNumber) {
		os.Exit(1)
	}
	max := math.MinInt32
	if max < firstNumber {
		max = firstNumber
	}
	if max < secondNumber {
		max = secondNumber
	}
	if max < thirdNumber {
		max = thirdNumber
	}
	fmt.Printf("The largest number is %d.\n", max)
}
