package main

import (
	"fmt"
	"strconv"
	"strings"
)

func validateSlice(input string) (bool, []int) {
	numberStr := strings.Fields(input)

	var numbers []int
	for _, e := range numberStr {
		intValue, err := strconv.Atoi(e)
		if err != nil {
			return false, []int{}
		}
		numbers = append(numbers, intValue)
	}
	return true, numbers
}

func main() {

	invalidMsg := "Sorry. That's not a valid input."
	inputArray := readUserInputWithValidator("Enter a list of numbers, separated by spaces: ", validateSlice, invalidMsg)
	evens := filterEvenNumbers(inputArray)

	fmt.Print("The even numbers are")
	for _, e := range evens {
		fmt.Printf(" %d", e)
	}
	fmt.Println(".")
}
