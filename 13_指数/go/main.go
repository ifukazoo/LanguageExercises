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

	fmt.Print("What is the principal amount? ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	principalAmount, err := strconv.Atoi(scanner.Text())
	if err != nil {
		os.Exit(1)
	}

	fmt.Print("What is the rate? ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	rate, err := strconv.ParseFloat(scanner.Text(), 64)
	if err != nil {
		os.Exit(1)
	}

	fmt.Print("What is the number of years? ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	numberOfYears, err := strconv.Atoi(scanner.Text())
	if err != nil {
		os.Exit(1)
	}

	fmt.Print("What is the number of times the interest is compounded per year? ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	numberOfYearsPerYear, err := strconv.Atoi(scanner.Text())
	if err != nil {
		os.Exit(1)
	}

	percent := rate / 100.0
	exponent := numberOfYears * numberOfYearsPerYear
	amount := float64(principalAmount) * math.Pow(1.0+(percent/float64(numberOfYearsPerYear)), float64(exponent))
	amount = math.Ceil(amount*100) / 100

	fmt.Printf("$%d invested at %.1f%% for %d years compounded %d times per year is $%.2f.\n",
		principalAmount, rate, numberOfYears, numberOfYearsPerYear, amount)
}
