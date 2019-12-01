package main

import "fmt"

func tablePrinter(begin func(), doWork func(int), end func()) {
	begin()
	for col := 0; col <= 12; col++ {
		doWork(col)
	}
	end()
}
func printHeader() {
	tablePrinter(
		func() { fmt.Printf("|    ") },
		func(col int) { fmt.Printf("|%4d", col) },
		func() { fmt.Printf("|\n") },
	)
}

func printHorizontalLine() {
	tablePrinter(
		func() { fmt.Printf("+----") },
		func(int) { fmt.Printf("+----") },
		func() { fmt.Printf("+\n") },
	)
}

func printRow(row int) {
	tablePrinter(
		func() { fmt.Printf("|%4d", row) },
		func(col int) { fmt.Printf("|%4d", row*col) },
		func() { fmt.Printf("|\n") },
	)
}

func main() {
	printHorizontalLine()
	printHeader()
	for i := 0; i <= 12; i++ {
		printHorizontalLine()
		printRow(i)
	}
	printHorizontalLine()
}
