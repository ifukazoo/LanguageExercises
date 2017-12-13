package main

import "testing"

func TestIsAnaglam(t *testing.T) {
	tests := []struct {
		input []string
		want  bool
	}{
		{[]string{"note", "tone"}, true},
		{[]string{"cinerama", "american"}, true},
		{[]string{"note", "TONE"}, false},
		{[]string{"note", "tonee"}, false},
		{[]string{"", ""}, true},
		{[]string{"n", "n"}, true},
	}
	for _, test := range tests {
		if got := isAnagram(test.input[0], test.input[1]); got != test.want {
			t.Errorf("%q = %v", test.input, got)
		}
	}
}
