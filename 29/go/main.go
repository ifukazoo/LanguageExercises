package main

import (
	"fmt"
	"os"
)

func main() {
	rate, err := readUserInput("What is the rate of return? ")
	if err != nil {
		fmt.Fprintln(os.Stderr, err.Error())
		os.Exit(1)
	}
	years := 72 / rate
	fmt.Printf("It will take %d years to double your initial investment.\n", years)
}
