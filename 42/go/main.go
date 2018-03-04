package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func printLine(left, mid, right string, leftW, midW, rightW int) {
	format := fmt.Sprintf("%%-%ds%%-%ds%%-%ds\n", leftW, midW, rightW)
	fmt.Printf(format, left, mid, right)
}
func printHr(leftW, midW, rightW int) {
	width := leftW + midW + rightW
	for width > 0 {
		fmt.Print("-")
		width--
	}
	fmt.Println("")
}
func main() {
	var scanner *bufio.Scanner

	if len(os.Args) == 1 {
		scanner = bufio.NewScanner(os.Stdin)
	} else {
		f, err := os.Open(os.Args[1])
		if err != nil {
			fmt.Fprintln(os.Stderr, err.Error())
			os.Exit(1)
		}
		defer f.Close()
		scanner = bufio.NewScanner(f)
	}

	csvLines := make([][]string, 0)
	for scanner.Scan() {
		csvLines = append(csvLines, strings.Split(scanner.Text(), ","))
	}

	// 列の最大長を計算
	var lastColW, firstColsW, salaryColsW int
	for _, csvLine := range csvLines {
		if len(csvLine[0]) > lastColW {
			lastColW = len(csvLine[0])
		}
		if len(csvLine[1]) > firstColsW {
			firstColsW = len(csvLine[1])
		}
		if len(csvLine[2]) > salaryColsW {
			salaryColsW = len(csvLine[2])
		}
	}

	// タイトル
	printLine("Last", "First", "Salary", lastColW+1, firstColsW+1, salaryColsW+1)

	// 水平線
	printHr(lastColW+1, firstColsW+1, salaryColsW+1)

	// 内容
	for _, csvLine := range csvLines {
		printLine(csvLine[0], csvLine[1], csvLine[2], lastColW+1, firstColsW+1, salaryColsW+1)
	}
}
