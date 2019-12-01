package main

import (
	"fmt"
	"strconv"
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

func validateNumber(input string) (bool, int) {
	num, err := strconv.Atoi(input)
	if err != nil {
		return false, 0
	}
	return true, num
}

const invalidMsg = "Sorry. That's not a valid input."

func main() {
	age := readUserInputWithValidator("Enter your age: ", validateNumber, invalidMsg)
	restingPulse := readUserInputWithValidator("Enter your resting pulse: ", validateNumber, invalidMsg)

	fmt.Println(title())
	fmt.Println(separator())
	for intensity := 55; intensity <= 95; intensity += 5 {
		rate := calcHeartRate(age, restingPulse, intensity)
		fmt.Println(heartRateLine(intensity, rate))
	}
}
