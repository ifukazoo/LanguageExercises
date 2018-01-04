#!/usr/bin/env python
# coding: -utf8
#

import math

def calc_heart_rate(age, resting_pulse, intensity_percent):
     # 公式
     # TargetHeartRate = (((220 − age) − restingHR) × intensity) + restingHR
    rate = (((220 - age) - resting_pulse) *
            intensity_percent / 100.0) + resting_pulse

    return math.floor(rate + 0.5)
