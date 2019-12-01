package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {

	scanner := bufio.NewScanner(os.Stdin)
	fmt.Println("Press C to convert from Fahrenheit to Celsius.")
	fmt.Println("Press F to convert from Celsius to Fahrenheit.")
	fmt.Printf("Your choice: ")

	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	choice := strings.ToUpper(scanner.Text())[0]
	var (
		from string
		to   string
	)
	if choice == 'C' {
		from = "Fahrenheit"
		to = "Celsius"
	} else {
		from = "Celsius"
		to = "Fahrenheit"
	}

	fmt.Printf("Please enter the temperature in %s: ", from)
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	source, err := strconv.ParseFloat(scanner.Text(), 64)
	if err != nil {
		os.Exit(1)
	}

	result := 0.0
	if to == "Celsius" {
		result = (source - 32.0) * 5.0 / 9.0
	} else {
		result = (source * 9.0 / 5.0) + 32.0
	}
	fmt.Printf("The temperature in %s is %.f\n", to, result)
}
