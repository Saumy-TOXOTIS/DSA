#include <bits/stdc++.h>
using namespace std;

long long power(long long base, int exp) {
    long long result = 1;
    for(int i = 0; i < exp; i++)
    {
        if(result > LLONG_MAX / base)
        {
            return LLONG_MAX; // avoid overflow
        }
        result *= base;
    }
    return result;
}

int NthRoot(int num, int n)
{
    int start = 1;
    int end = num;
    int ans = -1;
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        long long val = power(mid, n);
        if(val == num)
        {
            return mid;
        }
        else if(val < num)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1; // not a perfect nth root
}