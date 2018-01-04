package main

import "testing"

func TestCalcHeartRate(t *testing.T) {
	tests := []struct {
		input [3]int
		want  int
	}{
		{[3]int{22, 65, 55}, 138},
		{[3]int{22, 65, 60}, 145},
		{[3]int{22, 65, 65}, 151},
		{[3]int{22, 65, 70}, 158},
		{[3]int{22, 65, 75}, 165},
		{[3]int{22, 65, 80}, 171},
		{[3]int{22, 65, 85}, 178},
		{[3]int{22, 65, 90}, 185},
		{[3]int{22, 65, 95}, 191},
	}
	for _, test := range tests {
		if got := calcHeartRate(test.input[0], test.input[1], test.input[2]); got != test.want {
			t.Errorf("input %v, expect %v, but %v", test.input, test.want, got)
		}
	}
}
