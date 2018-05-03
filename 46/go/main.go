package main

import (
	"bufio"
	"flag"
	"fmt"
	"os"
	"sort"
	"strings"
	"unicode"
)

type freqmap map[string]int

type wordfreq struct {
	w string
	c int
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

func countWordFreq(path string) freqmap {
	f, err := os.Open(path)
	check(err)
	defer func() { check(f.Close()) }()

	scanner := bufio.NewScanner(f)
	freq := make(map[string]int)
	for scanner.Scan() {
		line := scanner.Text()
		words := strings.Fields(line)
		for _, w := range words {
			if maybeWord(w) {
				freq[w]++
			}
		}
	}
	check(scanner.Err())
	return freq
}

func getMaxWordLen(freq []wordfreq) int {
	max := 0
	for _, f := range freq {
		if max < len(f.w) {
			max = len(f.w)
		}
	}
	return max
}

func dispHist(freq []wordfreq) {
	maxWordlen := getMaxWordLen(freq)
	format := fmt.Sprintf("%%-0%ds", maxWordlen+2)
	for _, f := range freq {
		title := f.w + ": "
		fmt.Printf(format, title)
		star := ""
		for i := 0; i < f.c; i++ {
			star += "*"
		}
		fmt.Println(star)
	}
}

func maybeWord(word string) bool {
	for _, r := range word {
		if unicode.IsLetter(r) {
			return true
		}
	}
	return false
}

func main() {
	flag.Parse()
	if flag.NArg() < 1 {
		flag.Usage()
		os.Exit(1)
	}
	freqMap := countWordFreq(flag.Arg(0))
	freq := make([]wordfreq, len(freqMap))
	idx := 0
	for k, v := range freqMap {
		freq[idx] = wordfreq{k, v}
		idx++
	}
	sort.Slice(freq, func(i, j int) bool {
		return freq[i].c > freq[j].c
	})
	dispHist(freq)
}
