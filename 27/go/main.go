package main

import (
	"bufio"
	"fmt"
	"os"
)

var scanner *bufio.Scanner

func init() {
	scanner = bufio.NewScanner(os.Stdin)
}

func eInput(msg string) string {
	fmt.Printf(msg)
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	return scanner.Text()
}

func main() {
	firstName := eInput("Enter the first name: ")
	lastName := eInput("Enter the last name: ")
	zipCode := eInput("Enter the ZIP code: ")
	employeeID := eInput("Enter an employee ID: ")
	ok, err := validateInput(firstName, lastName, zipCode, employeeID)
	if ok {
		fmt.Printf("There were no errors found.\n")
	} else {
		fmt.Printf(err.Error())
	}
}
