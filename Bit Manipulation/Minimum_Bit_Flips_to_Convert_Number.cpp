#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int XOR = start^goal;
        int ans = 0;
        while(XOR > 0)
        {
            XOR = XOR&(XOR - 1);
            ans++;
        }
        return ans;
    }
};