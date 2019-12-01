#include <cmath>

#include "calculator.h"

int calculate_months_until_paid_off(int balance, int arp, int payment)
{
    // 公式
    // n = -(1/30) x log(1 + (b/p) x (1 - (1+i)^30)) / log(1+i)
    //
    // n is the number of months.
    // i is the daily rate (APR divided by 365).
    // b is the balance.
    // p is the monthly payment.

    auto i = static_cast<double>(arp) / 100.0 / 365;
    auto b = static_cast<double>(balance);
    auto p = static_cast<double>(payment);

    auto n = -(1.0 / 30.0) * log(1+(b/p)*(1-pow(1+i, 30))) / log(1+i);
    return static_cast<int>(ceil(n));
}
