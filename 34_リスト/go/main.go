package main

import (
	"fmt"
)

func dispEmployees(list []string) {
	fmt.Printf("There are %d  employees:\n", len(list))

	for _, e := range list {
		fmt.Println(e)
	}
}

func main() {
	employees := []string{
		"Jhon Smith", "Jackie Jackson", "Chris Jones",
		"Amanda Cullen", "Jeremy Goodwin"}

	dispEmployees(employees)

	fmt.Println("")
	name := readUserInput("Enter an employee name to remove: ")
	fmt.Println("")

	var newlist []string
	for _, e := range employees {
		if e != name {
			newlist = append(newlist, e)
		}
	}
	if len(employees) == len(newlist) {
		fmt.Printf("Not found %s.\n", name)
	} else {
		dispEmployees(newlist)
	}
}
