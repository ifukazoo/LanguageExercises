package main

import (
	"fmt"
	"math/rand"
	"strconv"
	"time"
)

const invalidMsg = "Sorry. That's not a valid input."

func generateGoalNumber(level int) int {
	r := rand.New(rand.NewSource(time.Now().UnixNano()))
	max := 1
	for i := 0; i < level; i++ {
		max *= 10
	}
	return r.Int()%max + 1
}

func validateNumber(input string) (bool, int) {
	intval, err := strconv.Atoi(input)
	if err != nil {
		return false, 0
	}
	return true, intval
}

func startGuess(level int) int {
	goal := generateGoalNumber(level)

	fmt.Print("I have my number. ")
	guess := readUserInputWithValidator("What's your guess? ", validateNumber, invalidMsg)
	tryCount := 1
	for guess != goal {
		if guess < goal {
			fmt.Print("Too low. ")
		} else {
			fmt.Print("Too high. ")
		}
		guess = readUserInputWithValidator("Guess again: ", validateNumber, invalidMsg)
		tryCount++
	}
	return tryCount
}

func validateLevel(input string) (bool, int) {
	level, err := strconv.Atoi(input)
	if err != nil {
		return false, 0
	}
	if !(level == 1 || level == 2 || level == 3) {
		return false, 0
	}
	return true, level
}

func startGame() {
	fmt.Print("Let's play Guess the Number.\n")

	level := readUserInputWithValidator("Pick a difficulty level (1, 2, or 3): ", validateLevel, invalidMsg)

	count := startGuess(level)

	fmt.Printf("You got it in %d guess!\n", count)
}
