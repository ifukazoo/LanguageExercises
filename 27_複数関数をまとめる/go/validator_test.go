package main

import "testing"

func TestValidateName(t *testing.T) {
	tests := []struct {
		input string
		want  bool
	}{
		{"", false},
		{"a", false},
		{"aa", true},
	}
	for _, test := range tests {
		if got := validateName(test.input); got != test.want {
			t.Errorf("input %v, expect %v, but %v", test.input, test.want, got)
		}
	}
}
func TestValidateEmployeeID(t *testing.T) {
	tests := []struct {
		input string
		want  bool
	}{
		{"AA-1234", true},
		{"zz-0000", true},

		{" AA-1234", false},
		{"", false},
		{"AA-1234 ", false},
		{"AA-1234\n", false},

		{"12-1234", false},
		{"-1234", false},
		{"A-1234", false},
		{"AAA-1234", false},
		{"A1-1234", false},

		{"AA 1234", false},
		{"AA1234", false},

		{"AA-aaaa", false},
		{"AA-", false},
		{"AA-234", false},
		{"AA-12345", false},
		{"AA-A234", false},
	}
	for _, test := range tests {
		if got := validateEmpoyeeID(test.input); got != test.want {
			t.Errorf("input %v, expect %v, but %v", test.input, test.want, got)
		}
	}
}
func TestvalidateZIPcode(t *testing.T) {
	tests := []struct {
		input string
		want  bool
	}{
		{"0", true},
		{"1", true},
		{"01", true},
		{"", false},
		{"a", false},
		{"g", false},
	}
	for _, test := range tests {
		if got := validateZIPcode(test.input); got != test.want {
			t.Errorf("input %v, expect %v, but %v", test.input, test.want, got)
		}
	}
}
