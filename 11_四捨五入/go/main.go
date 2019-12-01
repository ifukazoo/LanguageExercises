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

	fmt.Print("How many euros are you exchanging? ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	euros, err := strconv.Atoi(scanner.Text())
	if err != nil {
		os.Exit(1)
	}

	fmt.Print("What is the exchange rate? ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	rate, err := strconv.ParseFloat(scanner.Text(), 64)
	if err != nil {
		os.Exit(1)
	}

	usDollars := float64(euros) * rate / 100.0
	usDollars = math.Floor(usDollars*100.0+0.5) / 100

	fmt.Printf("%d euros at an exchante rate of %.2f is %.2f U.S. dollars.\n", euros, rate, usDollars)
}
