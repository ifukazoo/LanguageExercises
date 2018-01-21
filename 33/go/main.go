package main

import (
	"fmt"
	"math/rand"
	"time"
)

var r *rand.Rand

func init() {
	r = rand.New(rand.NewSource(time.Now().UnixNano()))
}

func generateRamdomIndex(max int) int {
	return r.Int() % max
}

func main() {

	answers := []string{"Yes", "No", "Maybe", "Ask again later"}
	readUserInput("What's your question? ")
	answer := answers[generateRamdomIndex(len(answers))]
	fmt.Printf("%s.\n", answer)
}
