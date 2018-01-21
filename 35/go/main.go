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

func generateRamdomNumber(max int) int {
	return r.Int() % max
}

func main() {
	var contestants []string
	for {
		name := readUserInput("Enter a name: ")
		if len(name) == 0 {
			break
		}
		contestants = append(contestants, name)
	}

	max := len(contestants)
	if max > 0 {
		winner := contestants[generateRamdomNumber(max)]
		fmt.Printf("The winner is .. %s.\n", winner)
	}

}
