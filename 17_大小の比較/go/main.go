package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {

	scanner := bufio.NewScanner(os.Stdin)

	fmt.Print("What is your weight? ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	weight, err := strconv.ParseFloat(scanner.Text(), 64)
	if err != nil {
		os.Exit(1)
	}

	fmt.Print("Which is your gender 1:male 2:femail ? ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	gender, err := strconv.Atoi(scanner.Text())
	if err != nil {
		os.Exit(1)
	}

	fmt.Print("What is the amount of alcohol by volume? ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	amountOfAlcohol, err := strconv.ParseFloat(scanner.Text(), 64)
	if err != nil {
		os.Exit(1)
	}

	fmt.Print("How long has it passed since you drunk? ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	numHours, err := strconv.Atoi(scanner.Text())
	if err != nil {
		os.Exit(1)
	}

	A := amountOfAlcohol
	W := weight
	var r float64
	if gender == 1 {
		r = 0.73
	} else {
		r = 0.66
	}
	H := float64(numHours)
	bac := (A * 5.14 / W * r) - 0.015*H
	// A is total alcohol consumed, in ounces (oz).
	// W is body weight in pounds.
	// r is the alcohol distribution ratio:
	//   0.73 for men
	//   0.66 for women
	// H is number of hours since the last drink.

	fmt.Printf("Your BAC is %.2f\n", bac)
	negator := ""
	if bac > 0.08 {
		negator = "not "
	}
	fmt.Printf("It is %slegal for you to drive.\n", negator)
}
