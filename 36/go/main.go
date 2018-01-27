package main

import (
	"fmt"
	"math"
	"strconv"
)

func validateNumberOrDone(input string) (bool, string) {
	if input == "done" {
		return true, input
	}
	_, err := strconv.Atoi(input)
	if err != nil {
		return false, ""
	}
	return true, input
}
func dispNums(nums []int) {
	fmt.Print("Numbers: ")
	sep := ""
	for _, n := range nums {
		fmt.Printf("%s%d", sep, n)
		sep = ", "
	}
	fmt.Println("")
}
func maximum(nums []int) int {
	if len(nums) == 0 {
		panic("size must not be zero.")
	}
	max := nums[0]
	for i := 0; i < len(nums); i++ {
		if nums[i] > max {
			max = nums[i]
		}
	}
	return max
}
func minimum(nums []int) int {
	if len(nums) == 0 {
		panic("size must not be zero.")
	}
	min := nums[0]
	for i := 0; i < len(nums); i++ {
		if nums[i] < min {
			min = nums[i]
		}
	}
	return min
}
func average(nums []int) float64 {
	if len(nums) == 0 {
		panic("size must not be zero.")
	}
	sum := 0.0
	for _, n := range nums {
		sum += float64(n)
	}
	return sum / float64(len(nums))
}

func standardDiviation(nums []int) float64 {
	if len(nums) == 0 {
		panic("size must not be zero.")
	}

	average := average(nums)
	tmpSum := 0.0
	for _, e := range nums {
		diff := average - float64(e)
		tmpSum += (diff * diff)
	}
	v := tmpSum / float64(len(nums))
	return math.Sqrt(v)
}

func main() {
	nums := []int{}
	for {
		input := readUserInputWithValidator("Enter a number: ",
			validateNumberOrDone, "Sorry. That's not a valid input.")
		if input == "done" {
			break
		} else {
			val, _ := strconv.Atoi(input)
			nums = append(nums, val)
		}
	}
	if len(nums) > 0 {
		dispNums(nums)
		fmt.Printf("The average is %.0f\n", average(nums))
		fmt.Printf("The minimum is %d\n", minimum(nums))
		fmt.Printf("The maximum is %d\n", maximum(nums))
		fmt.Printf("The standard deviation is %.2f\n", standardDiviation(nums))
	}
}
