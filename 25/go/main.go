package main

import (
	"fmt"

	"./validator"
)

func output(s string) {
	strength := validator.PasswordValidator(s)
	fmt.Printf("The password '%s' is a %s password.\n", s, strength.String())
}

func main() {
	output("12345")
	output("abcdef")
	output("abc123xyz")
	output("1337h@xor!")
}
