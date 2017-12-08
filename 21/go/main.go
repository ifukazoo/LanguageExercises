package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {

	scanner := bufio.NewScanner(os.Stdin)

	fmt.Print("Enter the number of the month: ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	number, err := strconv.Atoi(scanner.Text())
	if err != nil {
		os.Exit(1)
	}

	var month string
	switch number {
	case 1:
		month = "January"
	case 2:
		month = "February"
	case 3:
		month = "March"
	case 4:
		month = "April"
	case 5:
		month = "May"
	case 6:
		month = "June"
	case 7:
		month = "July"
	case 8:
		month = "August"
	case 9:
		month = "September"
	case 10:
		month = "October"
	case 11:
		month = "November"
	case 12:
		month = "December"
	default:
		os.Exit(1)
	}
	fmt.Printf("The name of the month is %s.\n", month)
}
