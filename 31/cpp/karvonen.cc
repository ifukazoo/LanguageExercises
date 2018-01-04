#include "karvonen.h"

#include <cmath>

int calc_heart_rate(int age, int resting_pulse, int intensity_percent) {
    // 公式
    // TargetHeartRate = (((220 − age) − restingHR) × intensity) + restingHR
    double rate = (((220 - age) - resting_pulse) * intensity_percent / 100.0) +
                  resting_pulse;

    return round(rate);
}
