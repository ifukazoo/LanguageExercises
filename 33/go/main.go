package main

import (
	"fmt"
	"math/rand"
	"time"
)

func generateRamdomIndex(max int) int {
	r := rand.New(rand.NewSource(time.Now().UnixNano()))
	return r.Int() % max
}

func main() {

	answers := []string{"Yes", "No", "Maybe", "Ask again later"}
	readUserInput("What's your question? ")
	answer := answers[generateRamdomIndex(len(answers))]
	fmt.Printf("%s.\n", answer)
}
