package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {

	scanner := bufio.NewScanner(os.Stdin)

	fmt.Print("Enter your height(inch): ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	height, err := strconv.ParseFloat(scanner.Text(), 64)
	if err != nil {
		os.Exit(1)
	}

	fmt.Print("Enter your weight(pound): ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	weight, err := strconv.ParseFloat(scanner.Text(), 64)
	if err != nil {
		os.Exit(1)
	}

	bmi := (weight / (height * height)) * 703
	bmi = ((bmi * 10) + 0.5) / 10.0

	fmt.Printf("Yor BMI is %.1f.\n", bmi)
	if bmi < 18.5 {
		fmt.Println("Yor are underweight. You should see your doctor.")
	} else if 18.5 <= bmi && bmi <= 25 {
		fmt.Println("Yor are whthin the ideal weight range.")
	} else {
		fmt.Println("Yor are overweight. You should see your doctor.")
	}
}
