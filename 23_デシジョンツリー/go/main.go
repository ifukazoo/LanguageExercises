package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {

	scanner := bufio.NewScanner(os.Stdin)

	// 1
	fmt.Print("Is the car silent when you turn the key? ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	answer := strings.ToUpper(scanner.Text())[0]
	if answer == 'Y' {
		// 2
		fmt.Print("Are the battery terminals corroded? ")
		scanner.Scan()
		if scanner.Err() != nil {
			os.Exit(1)
		}
		answer := strings.ToUpper(scanner.Text())[0]
		if answer == 'Y' {
			// 4
			fmt.Println("Clean terminals and try starting again.")
		} else {
			// 5
			fmt.Println("Replace cables and try again.")
		}
	} else {
		// 3
		fmt.Print("Does the car make a clicking noise? ")
		scanner.Scan()
		if scanner.Err() != nil {
			os.Exit(1)
		}
		answer := strings.ToUpper(scanner.Text())[0]
		if answer == 'Y' {
			// 6
			fmt.Println("Replace the battery.")
		} else {
			// 7
			fmt.Print("Does the car crank up but fail to start? ")
			scanner.Scan()
			if scanner.Err() != nil {
				os.Exit(1)
			}
			answer := strings.ToUpper(scanner.Text())[0]
			if answer == 'Y' {
				// 8
				fmt.Println("Check spark plug connections.")
			} else {
				// 9
				fmt.Print("Does the engine start and then die? ")
				scanner.Scan()
				if scanner.Err() != nil {
					os.Exit(1)
				}
				answer := strings.ToUpper(scanner.Text())[0]
				if answer == 'Y' {
					// 10
					fmt.Print("Does your car have fuel injection? ")
					scanner.Scan()
					if scanner.Err() != nil {
						os.Exit(1)
					}
					answer := strings.ToUpper(scanner.Text())[0]
					if answer == 'Y' {
						// 12
						fmt.Println("Get it in for service.")
					} else {
						// 11
						fmt.Println("Check to ensure the choke is opening and closing.")
					}
				} else {
					// nothing
				}
			}
		}
	}
}
