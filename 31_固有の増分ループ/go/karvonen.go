package main

import "math"

func calcHeartRate(age, restingPulse, intensityPercent int) int {
	// 公式
	// TargetHeartRate = (((220 − age) − restingHR) × intensity) + restingHR
	rate := float64(((220 - age) - restingPulse) * intensityPercent)
	rate = rate/100.0 + float64(restingPulse)

	return int(math.Floor(rate + 0.5))
}
