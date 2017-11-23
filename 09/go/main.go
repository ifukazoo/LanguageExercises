package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

const paintablePerGallon = 350.0

func main() {

	scanner := bufio.NewScanner(os.Stdin)

	fmt.Print("What is the length of the room in feet? ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	lengthRoom, err := strconv.Atoi(scanner.Text())
	if err != nil {
		os.Exit(1)
	}

	fmt.Print("What is the width of the room in feet? ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	widthRoom, err := strconv.Atoi(scanner.Text())
	if err != nil {
		os.Exit(1)
	}

	squareFeet := lengthRoom * widthRoom
	gallon := float64(squareFeet) / paintablePerGallon
	numGallon := int(math.Ceil(gallon))

	fmt.Printf("You will need to purchase %d gallons of paint to cover %d square feet.\n", numGallon, squareFeet)

	return
}
