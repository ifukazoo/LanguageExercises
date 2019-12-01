package main

func filterEvenNumbers(inputArray []int) []int {
	evens := []int{}
	for _, e := range inputArray {
		if e%2 == 0 {
			evens = append(evens, e)
		}
	}
	return evens
}
