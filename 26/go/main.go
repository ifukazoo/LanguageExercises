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
	var input string

	input = eInput("What is your balance? ")
	balance, err := strconv.Atoi(input)
	if err != nil {
		os.Exit(1)
	}

	input = eInput("What is the ARP on the card (as a percent)? ")
	arp, err := strconv.Atoi(input)
	if err != nil {
		os.Exit(1)
	}

	input = eInput("What is the monthly payment you can make? ")
	payment, err := strconv.Atoi(input)
	if err != nil {
		os.Exit(1)
	}

	months, err := calculateMonthsUntilPaidOff(balance, arp, payment)
	if err != nil {
		fmt.Printf("You can't pay off this card.\n")
		os.Exit(1)
	}
	fmt.Printf("It will take you %d months to pay off this card.\n", months)
}
