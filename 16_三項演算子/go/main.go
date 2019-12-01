package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const legalDrivingAge = 16

func main() {

	scanner := bufio.NewScanner(os.Stdin)
	fmt.Printf("What is your age? ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	age := strconv.Atoi(scanner.Text())
	if age < kLegalDrivingAge {
		fmt.Println("You are not old enough to legally drive.")
	} else {
		fmt.Println("You are old enough to legally drive.")
	}
}
