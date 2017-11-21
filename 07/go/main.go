package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

const feetToMeterCoff = 0.09290304

func main() {

	scanner := bufio.NewScanner(os.Stdin)

	fmt.Print("What is the length of the room in feet? ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	length, err := strconv.Atoi(scanner.Text())
	if err != nil {
		os.Exit(1)
	}

	fmt.Print("What is the width of the room  n feet? ")
	scanner.Scan()
	if scanner.Err() != nil {
		os.Exit(1)
	}
	width, err := strconv.Atoi(scanner.Text())
	if err != nil {
		os.Exit(1)
	}

	fmt.Printf("You entered dimensions of %d feet by %d feet.\n", length, width)

	// フィート値
	feet := length * width

	// メートル値

	// 整数値で計算
	meters := float64(feet * (feetToMeterCoff * 100000000))
	// 小数点4桁目を四捨五入
	meters /= 100000.0
	meters = math.Floor(meters + 0.5)
	meters /= 1000.0

	fmt.Printf("The area is \n")
	fmt.Printf("%d square feet\n", feet)
	fmt.Printf("%.3f square meters\n", meters)
}
