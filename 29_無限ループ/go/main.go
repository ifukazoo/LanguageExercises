package main

import (
	"fmt"
	"strconv"
)

func main() {
	rate := readUserInputWithValidator(
		"What is the rate of return? ",
		validateRate,
		"Sorry. That's not a valid input.")
	years := 72 / rate
	fmt.Printf("It will take %d years to double your initial investment.\n", years)
}

func validateRate(input string) (bool, int) {
	rate, err := strconv.Atoi(input)
	if err != nil {
		return false, 0
	}
	if rate == 0 {
		return false, 0
	}
	return true, rate
}
