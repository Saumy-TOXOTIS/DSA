#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<int,int> memo;
    int minimumOneBitOperations(int n)
    {
        if(n == 0)
        {
            return 0;
        }
        if(memo.count(n))
        {
            return memo[n];
        }
        int msb = 1;
        while((msb<<1) <= n)
        {
            msb <<= 1;
        }
        int msb_cost = (msb<<1) - 1;
        int b = n - msb;
        int rem_cost = minimumOneBitOperations(b);
        return memo[n] = msb_cost - rem_cost;
    }
};