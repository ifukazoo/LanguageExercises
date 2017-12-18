package validator

import "testing"

func TestPasswordValidator(t *testing.T) {
	tests := []struct {
		input string
		want  Strength
	}{
		{"", VeryWeak},
		{"1234567", VeryWeak},
		{"aaaaaaa", Weak},
		{"aaaaaa@", Normal},
		{"123456@", Normal},

		{"aaaaaaaa", Normal},
		{"12345678", Normal},
		{"########", Normal},
		{"aaaaaaa8", Strong},
		{"1234567a", Strong},
		{"aaaaaa#8", VeryStrong},
		{"123456#a", VeryStrong},
	}
	for _, test := range tests {
		if got := PasswordValidator(test.input); got != test.want {
			t.Errorf("%q = %v", test.input, got)
		}
	}
}
