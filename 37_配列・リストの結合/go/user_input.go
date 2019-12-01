package main

import (
	"bufio"
	"fmt"
	"os"
)

type stringValidator func(string) (bool, string)
type intValidator func(string) (bool, int)

var scanner *bufio.Scanner

func init() {
	scanner = bufio.NewScanner(os.Stdin)
}

// input プロンプトを出してユーザー入力を取得する.
func input(prompter string) (string, error) {
	_, err := fmt.Printf(prompter)
	if err != nil {
		return "", err
	}
	if !scanner.Scan() {
		if scanner.Err() == nil {
			// EOF
			return "", fmt.Errorf("interrupted by EOF")
		}
		// ERROR
		return "", scanner.Err()
	}
	return scanner.Text(), nil
}

// readUserInput プロンプトを出してユーザー入力を取得する.
// EOFが入力された場合はプログラム終了する
func readUserInput(prompter string) string {
	userInput, err := input(prompter)
	if err != nil {
		fmt.Fprintln(os.Stderr, err.Error())
		os.Exit(1)
	}
	return userInput
}

// readUserInputWithValidator プロンプトを出してユーザー入力を取得して,
// 希望の型に変換する.希望に沿わない入力だった場合は再度入力をうながす.
func readUserInputWithValidator(prompter string, validator intValidator, invalidMsg string) int {

retry:
	input := readUserInput(prompter)
	ok, value := validator(input)
	if !ok {
		fmt.Println(invalidMsg)
		goto retry
	}
	return value
}
