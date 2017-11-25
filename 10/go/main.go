package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	repeatCount = 3
	taxRate     = 5.5
)

type pair struct {
	first  int
	second int
}

func main() {

	items := make([]pair, repeatCount)

	scanner := bufio.NewScanner(os.Stdin)

	for i := 0; i < repeatCount; i++ {
		fmt.Printf("Enter the price of item %d: ", i+1)
		scanner.Scan()
		if scanner.Err() != nil {
			os.Exit(1)
		}
		price, err := strconv.Atoi(scanner.Text())
		if err != nil {
			os.Exit(1)
		}
		items[i].first = price

		fmt.Printf("Enter the quantity of item %d: ", i+1)
		scanner.Scan()
		if scanner.Err() != nil {
			os.Exit(1)
		}
		quantity, err := strconv.Atoi(scanner.Text())
		if err != nil {
			os.Exit(1)
		}
		items[i].second = quantity
	}

	subtotal := 0
	for i := 0; i < repeatCount; i++ {
		price := items[i].first * items[i].second
		subtotal += price
	}
	tax := float64(subtotal) * taxRate / 100.0
	total := float64(subtotal) + tax
	fmt.Printf("Subtotal: $%.2f\n", float64(subtotal))
	fmt.Printf("Tax: $%.2f\n", tax)
	fmt.Printf("Total: $%.2f\n", total)

	return
}
