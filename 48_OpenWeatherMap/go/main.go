package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"net/http"
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

func main() {

	invalidMsg := "Sorry. That's not a valid input."
	appid := readWithValidator("What is your openweather api appid? ", validateNotEmpty, invalidMsg)
	city := readWithValidator("Where are you? ", validateNotEmpty, invalidMsg)

	url := fmt.Sprintf("http://api.openweathermap.org/data/2.5/weather?q=%s&APPID=%s&units=metric", city, appid)
	res, err := http.Get(url)
	check(err)
	if !strings.HasPrefix(res.Status, "20") {
		fmt.Println(res.Status)
		return
	}
	defer res.Body.Close()
	reader := bufio.NewReader(res.Body)

	var result Rootobject
	err = json.NewDecoder(reader).Decode(&result)
	check(err)
	if result.Cod == 200 {
		fmt.Printf("%s weather: %s\n", city, result.Weather[0].Main)
		fmt.Printf("%.2f degrees Celsius\n", result.Main.Temp)
	}
}
