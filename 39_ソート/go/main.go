package main

import (
	"fmt"
	"sort"
)

// Employee 従業員
type Employee struct {
	firstName      string
	lastName       string
	position       string
	separationDate string
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

func main() {
	employees := []*Employee{
		{"John", "Johnson", "Manager", "2016-12-31"},
		{"Tou", "Xiong", "Software Engineer", "2016-10-05"},
		{"Michaela", "Michaelson", "District Manager", "2015-12-19"},
		{"Jake", "Jacobson", "Programmer", ""},
		{"Jacquelyn", "Jackson", "DBA", ""},
		{"Sally", "Weber", "Web Developer", "2015-12-18"},
	}
	sort.Slice(employees, func(i, j int) bool {
		return employees[i].lastName < employees[j].lastName
	})
	printRow("Name", " Position", " Separation Date")
	printRow("-----------------------", "----------------------",
		"----------------------")
	for _, employee := range employees {
		printRow(employee.firstName+" "+employee.lastName,
			" "+employee.position, " "+employee.separationDate)
	}
}
