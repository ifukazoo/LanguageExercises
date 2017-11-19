package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"time"
)

func main() {

	scanner := bufio.NewScanner(os.Stdin)

	fmt.Print("What is your current age? ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	age, err := strconv.Atoi(scanner.Text())
	if err != nil {
		os.Exit(1)
	}

	fmt.Print("At what age would you like to retire? ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	retireAge, err := strconv.Atoi(scanner.Text())
	if err != nil {
		os.Exit(1)
	}

	thisYear := time.Now().Year()
	fmt.Printf("You have %d years left until you can retire.\n", retireAge-age)
	fmt.Printf("It's %d, so you can retire in %d\n", thisYear, thisYear+retireAge-age)
}
