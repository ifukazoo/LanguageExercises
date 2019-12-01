package main

import (
	"fmt"
	"strings"
)

// Employee 従業員
type Employee struct {
	firstName      string
	lastName       string
	position       string
	separationDate string
}

func filterEmployee(employees []*Employee, filter func(e *Employee) bool) []*Employee {
	result := make([]*Employee, 0)
	for _, e := range employees {
		if filter(e) {
			result = append(result, e)
		}
	}
	return result
}

func printCel(s string) {
	fmt.Printf("%-23s", s)
}

func printRow(left, middle, right string) {
	printCel(left)
	printCel("|" + middle)
	printCel("|" + right)
	fmt.Println("")
}
func printResult(employees []*Employee) {
	printRow("Name", " Position", " Separation Date")
	printRow("-----------------------", "----------------------", "----------------------")
	for _, e := range employees {
		printRow(e.firstName+" "+e.lastName,
			" "+e.position, " "+e.separationDate)
	}
}

func everyInputOk(s string) (bool, string) {
	return true, s
}

func main() {
	employees := []*Employee{
		{"John", "Johnson", "Manager", "2016-12-31"},
		{"Tou", "Xiong", "Software Engineer", "2016-10-05"},
		{"Michaela", "Michaelson", "District Manager", "2015-12-19"},
		{"Jake", "Jacobson", "Programmer", ""},
		{"Jacquelyn", "Jackson", "DBA", ""},
		{"Sally", "Weber", "Web Developer", "2015-12-18"},
	}

	searchString := readUserInputWithValidator(
		"Enter a search string: ", everyInputOk, "")

	result := filterEmployee(employees, func(e *Employee) bool {
		return strings.Contains(e.lastName, searchString) || strings.Contains(e.lastName, searchString)
	})

	printResult(result)
}
