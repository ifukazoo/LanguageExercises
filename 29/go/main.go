package main

import (
	"fmt"
	"os"
)

func main() {
	invalidMsg := "Sorry. That's not a valid input."

retry:
	rate, err := readUserInput("What is the rate of return? ", invalidMsg)
	if err != nil {
		fmt.Fprintln(os.Stderr, err.Error())
		os.Exit(1)
	}
	if rate == 0 {
		fmt.Println(invalidMsg)
		goto retry
	}
	years := 72 / rate
	fmt.Printf("It will take %d years to double your initial investment.\n", years)
}
