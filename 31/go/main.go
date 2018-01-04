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
			return "", fmt.Errorf("user input eof")
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

func partitionFormat(left, right string) string {
	return left + "|" + right
}

func title() string {
	return partitionFormat("Intensity\t", " Rate")
}

func separator() string {
	return partitionFormat("----------------", "----------")
}

func heartRateLine(intensity, rate int) string {
	left := fmt.Sprintf("%d%%\t\t", intensity)
	right := fmt.Sprintf(" %d bpm", rate)
	return partitionFormat(left, right)
}

func exitByEOF() {
	fmt.Fprintf(os.Stderr, "failed to read user input.\n")
	os.Exit(1)
}

func main() {
	age, err := readUserInput("Enter your age: ")
	if err != nil {
		exitByEOF()
	}
	restingPulse, err := readUserInput("Enter your resting pulse: ")
	if err != nil {
		exitByEOF()
	}

	fmt.Println(title())
	fmt.Println(separator())
	for intensity := 55; intensity <= 95; intensity += 5 {
		rate := calcHeartRate(age, restingPulse, intensity)
		fmt.Println(heartRateLine(intensity, rate))
	}
}
