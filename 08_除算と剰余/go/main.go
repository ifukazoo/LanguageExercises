package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const piecesPerPizza = 8

func main() {

	scanner := bufio.NewScanner(os.Stdin)

	fmt.Print("How many people? ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	numPeople, err := strconv.Atoi(scanner.Text())
	if err != nil {
		os.Exit(1)
	}

	fmt.Print("How many pizzas do you have? ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	numPizzas, err := strconv.Atoi(scanner.Text())
	if err != nil {
		os.Exit(1)
	}

	fmt.Printf("%d people with %d pizzas\n", numPeople, numPizzas)

	numPieces := piecesPerPizza * numPizzas
	qutient := numPieces / numPeople
	remainder := numPieces % numPeople

	fmt.Printf("Each person gets %d pieces of pizza.\n", qutient)
	fmt.Printf("Threre are %d leftover pieces.\n", remainder)
}
