package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var scanner *bufio.Scanner

func init() {
	scanner = bufio.NewScanner(os.Stdin)
}

func input(msg string) (string, error) {
	_, err := fmt.Printf(msg)
	if err != nil {
		return "", err
	}
	if !scanner.Scan() {
		if scanner.Err() == nil {
			// EOF
			return "", fmt.Errorf("interrupted by EOF")
		}
		// ERROR
		return "", scanner.Err()
	}
	return scanner.Text(), nil
}

func readUserInput(prompter string) (int, error) {
	for {
		userInput, err := input(prompter)
		if err != nil {
			// EOF or ERROR
			return 0, err
		}
		intValue, err := strconv.Atoi(userInput)
		if err != nil {
			fmt.Printf("Sorry. That's not a valid input.\n")
			continue
		}
		return intValue, nil
	}
}
