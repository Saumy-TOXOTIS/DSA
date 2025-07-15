#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if(dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }
        bool is_negative = (dividend < 0) ^ (divisor < 0);
        long long abs_dividend = abs((long long)dividend);
        long long abs_divisor = abs((long long)divisor);
        long long quotient = 0;
        while(abs_dividend >= abs_divisor)
        {
            long long temp_divisor = abs_divisor;
            long long multiple = 1;
            while(abs_dividend >= (temp_divisor << 1))
            {
                temp_divisor <<= 1;
                multiple <<= 1;
            }
            abs_dividend -= temp_divisor;
            quotient += multiple;
        }
        return is_negative ? -quotient : quotient;
    }
};