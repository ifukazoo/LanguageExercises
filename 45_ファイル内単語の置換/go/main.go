package main

import (
	"bufio"
	"flag"
	"fmt"
	"os"
	"strings"
)

func validateNotEmpty(s string) (bool, string) {
	trimed := strings.TrimSpace(s)
	if len(trimed) == 0 {
		return false, ""
	}
	return true, trimed
}

func check(err error) {
	if err != nil {
		fmt.Fprintf(os.Stderr, "failed:%s\n", err.Error())
		os.Exit(1)
	}
}

func init() {
	flag.Usage = func() {
		fmt.Fprintf(os.Stderr, "Usage: %s <input file name>\n", os.Args[0])
		flag.PrintDefaults()
	}
}

func main() {
	flag.Parse()
	if flag.NArg() < 1 {
		flag.Usage()
		os.Exit(1)
	}

	in, err := os.Open(flag.Arg(0))
	check(err)
	defer in.Close()
	reader := bufio.NewScanner(in)

	invalidMsg := "Sorry. That's not a valid input."
	name := readUserInputWithValidator("What is the output file name? ", validateNotEmpty, invalidMsg)

	out, err := os.Create(name)
	check(err)
	defer out.Close()

	for reader.Scan() {
		err := reader.Err()
		check(err)

		line := reader.Text() + "\n"
		newline := strings.Replace(line, "utilize", "use", -1)
		remain := len(newline)
		off := 0
		data := []byte(newline)
		for remain > 0 {
			written, err := out.Write(data[off:])
			check(err)
			remain -= written
			off += written
		}
	}
}
