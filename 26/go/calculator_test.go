package main

import "testing"

func TestCalculateMonthsUntilPaidOff(t *testing.T) {
	tests := []struct {
		input [3]int
		want  int
	}{
		{[3]int{5000, 12, 100}, 70},
	}
	for _, test := range tests {
		if got, _ := calculateMonthsUntilPaidOff(test.input[0], test.input[1], test.input[2]); got != test.want {
			t.Errorf("input %v, expect %v, but %v", test.input, test.want, got)
		}
	}
}
