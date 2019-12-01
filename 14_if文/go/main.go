package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

const taxWI = 5.5

func main() {

	scanner := bufio.NewScanner(os.Stdin)

	fmt.Print("What is the order amount? ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	amount, err := strconv.ParseFloat(scanner.Text(), 64)
	if err != nil {
		os.Exit(1)
	}

	fmt.Print("What is the state? ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	state := scanner.Text()
	if err != nil {
		os.Exit(1)
	}

	var tax float64
	if state == "WI" {
		tax = amount * (taxWI / 100.0)
		fmt.Printf("The subtotal is $%.2f.\n", amount)
		fmt.Printf("The tax is $%.2f.\n", tax)
	}
	totalAmount := math.Floor(((amount+tax)*100)+0.5) / 100.0
	fmt.Printf("The total is $%.2f.\n", totalAmount)
}
