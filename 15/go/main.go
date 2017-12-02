package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {

	passwordData := map[string]string{
		"figaro":   "abcd",
		"susanna":  "1234",
		"almaviva": "ABCD",
		"rosina":   "5678",
	}

	scanner := bufio.NewScanner(os.Stdin)

	fmt.Print("What is the usernames? ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	inputUserName := scanner.Text()

	fmt.Print("What is the password? ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	inputPassword := scanner.Text()

	if password, ok := passwordData[inputUserName]; !ok {
		fmt.Println("I don't know you.")
	} else {
		if inputPassword == password {
			fmt.Println("Welcome!")
		} else {
			fmt.Println("I don't know you.")
		}
	}
}
