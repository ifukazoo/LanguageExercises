package main

import (
	"fmt"
	"os"
)

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

func main() {
	invalidMsg := "Sorry. That's not a valid input."
	age, err := readUserInput("Enter your age: ", invalidMsg)
	if err != nil {
		fmt.Fprintln(os.Stderr, err.Error())
		os.Exit(1)
	}
	restingPulse, err := readUserInput("Enter your resting pulse: ", invalidMsg)
	if err != nil {
		fmt.Fprintln(os.Stderr, err.Error())
		os.Exit(1)
	}

	fmt.Println(title())
	fmt.Println(separator())
	for intensity := 55; intensity <= 95; intensity += 5 {
		rate := calcHeartRate(age, restingPulse, intensity)
		fmt.Println(heartRateLine(intensity, rate))
	}
}
