package main

import (
	"fmt"
	"math"
)

func calculateMonthsUntilPaidOff(balance int, arp int, payment int) (int, error) {
	// 公式
	// n = -(1/30) x log(1 + (b/p) x (1 - (1+i)^30)) / log(1+i)
	//
	// n is the number of months.
	// i is the daily rate (APR divided by 365).
	// b is the balance.
	// p is the monthly payment.

	i := float64(arp) / 100.0 / 365
	b := float64(balance)
	p := float64(payment)

	n := -(1.0 / 30.0) * math.Log(1+(b/p)*(1-math.Pow(1+i, 30))) / math.Log(1+i)
	if math.IsNaN(n) {
		return 0, fmt.Errorf("can't paid off")
	}
	return int(math.Ceil(n)), nil
}
