package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func printResult(path string, names []string) (err error) {
	f, err := os.Create(path)
	if err != nil {
		return
	}
	defer func() { err = f.Close() }()

	if _, err = f.WriteString(fmt.Sprintf("Total of %d names\n", len(names))); err != nil {
		return
	}
	if _, err = f.WriteString("-----------------\n"); err != nil {
		return
	}
	for _, name := range names {
		if _, err = f.WriteString(name + "\n"); err != nil {
			return
		}
	}
	return
}

func main() {
	names := make([]string, 0)
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		names = append(names, scanner.Text())
	}
	sort.Strings(names)
	if err := printResult("result", names); err != nil {
		fmt.Fprintln(os.Stderr, err.Error())
		os.Exit(1)
	}
}
