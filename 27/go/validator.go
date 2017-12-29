package main

import (
	"bytes"
	"errors"
	"fmt"
	"regexp"
	"unicode"
)

func validateInput(firstName, lastName, zipCode, employeeID string) (bool, error) {
	errMsg := bytes.NewBufferString("")
	if _, err := validateNameAndMakeError(firstName, "first"); err != nil {
		// bytes.WriteString()  err always nil.
		errMsg.WriteString(err.Error() + ".\n")
	}
	if _, err := validateNameAndMakeError(lastName, "last"); err != nil {
		errMsg.WriteString(err.Error() + ".\n")
	}
	if !validateZIPcode(zipCode) {
		errMsg.WriteString("The ZIP code must be numeric.\n")
	}
	if !validateEmpoyeeID(employeeID) {
		errMsg.WriteString(fmt.Sprintf("%s is not a valid ID.\n", employeeID))
	}
	return errMsg.Len() == 0, errors.New(errMsg.String())
}
func validateNameAndMakeError(input, firstOrLast string) (bool, error) {
	if len(input) == 0 {
		return false, fmt.Errorf("The %s name must be filled in", firstOrLast)
	}
	if !validateName(input) {
		return false, fmt.Errorf("\"%s\" is not a valid %s name. It is too short", input, firstOrLast)
	}
	return true, nil
}

func validateName(input string) bool {
	return len(input) >= 2
}

func validateEmpoyeeID(input string) bool {
	re := regexp.MustCompile(`\A[a-zA-Z]{2}-\d{4}\z`)
	return re.MatchString(input)
}

func validateZIPcode(input string) bool {
	if len(input) == 0 {
		return false
	}
	return allOf(input, unicode.IsDigit)
}

func allOf(input string, f func(rune) bool) bool {
	for _, r := range input {
		if !f(r) {
			return false
		}
	}
	return true
}
