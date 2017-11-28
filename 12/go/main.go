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

	fmt.Print("Enter the principal: ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	principal, err := strconv.Atoi(scanner.Text())
	if err != nil {
		os.Exit(1)
	}

	fmt.Print("Enter the rate of interest: ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	rateOfInterest, err := strconv.ParseFloat(scanner.Text(), 64)
	if err != nil {
		os.Exit(1)
	}

	fmt.Print("Enter the number of years: ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	years, err := strconv.Atoi(scanner.Text())
	if err != nil {
		os.Exit(1)
	}

	amount := float64(principal) * (1 + ((rateOfInterest / 100.0) * float64(years)))
	amount = math.Floor(amount*100.0 + 0.5)
	amount = amount / 100.0

	fmt.Printf("After %d years at %.1f%%, the investment will be worth $%.2f.\n", years, rateOfInterest, amount)
}
