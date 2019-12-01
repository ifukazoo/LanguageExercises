package main

import (
	"fmt"
	"strings"
)

func userWantToContinue() bool {
	answer := readUserInput("Play again? ")
	return strings.ToUpper(answer)[0] == 'Y'
}

func main() {
	for {
		startGame()
		if !userWantToContinue() {
			break
		}
	}
	fmt.Println("Goodbye!")
}
