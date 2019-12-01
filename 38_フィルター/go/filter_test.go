package main

import (
	"reflect"
	"testing"
)

func TestFilterEvenNumbers(t *testing.T) {
	tests := []struct {
		input []int
		want  []int
	}{
		{[]int{}, []int{}},
		{[]int{1}, []int{}},
		{[]int{1, 3}, []int{}},
		{[]int{0}, []int{0}},
		{[]int{0, 1, 2}, []int{0, 2}},
	}
	for _, test := range tests {
		if got := filterEvenNumbers(test.input); !reflect.DeepEqual(got, test.want) {
			t.Errorf("input %v, expect %v, but %v", test.input, test.want, got)
		}
	}
}
