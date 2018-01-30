package main

import (
	"fmt"
	"math/rand"
	"strconv"
	"time"
)

const (
	alphabets    = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
	numbers      = "0123456789"
	specialChars = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~}"
)

var r *rand.Rand

func init() {
	r = rand.New(rand.NewSource(time.Now().UnixNano()))
}

func generateRamdomNumber(max int) int {
	return r.Int() % max
}
func validateNumber(input string) (bool, int) {
	number, err := strconv.Atoi(input)
	if err != nil {
		return false, 0
	}
	return true, number
}

func generatePassword(numSpecial, numNumber, numMin int) string {
	if numSpecial+numNumber > numMin {
		panic("not enough length numMin")
	}

	// パスワードに使う文字を集める
	var charactersSelected []byte
	for i := 0; i < numSpecial; i++ {
		charactersSelected = append(charactersSelected, specialChars[generateRamdomNumber(len(specialChars))])
	}

	for i := 0; i < numNumber; i++ {
		charactersSelected = append(charactersSelected, numbers[generateRamdomNumber(len(numbers))])
	}

	for i := 0; i < numMin-numSpecial-numNumber; i++ {
		charactersSelected = append(charactersSelected, alphabets[generateRamdomNumber(len(alphabets))])
	}

	// ランダムに並べ替える
	remain := len(charactersSelected)
	iterMax := len(charactersSelected) - 1
	for i := 0; i < iterMax; i++ {
		rIdx := r.Int() % remain
		// 入れ替える
		charactersSelected[i], charactersSelected[i+rIdx] = charactersSelected[i+rIdx], charactersSelected[i]
		remain--
	}
	return string(charactersSelected)
}

func main() {

	invalidMsg := "Sorry. That's not a valid input."
	numMin := readUserInputWithValidator("What's the minimum length? ", validateNumber, invalidMsg)

	numSpecial := readUserInputWithValidator("How many special characters? ", validateNumber, invalidMsg)

	numNumber := readUserInputWithValidator("How many numbers? ", validateNumber, invalidMsg)

	password := generatePassword(numSpecial, numNumber, numMin)

	fmt.Printf("%s\n", password)
}
