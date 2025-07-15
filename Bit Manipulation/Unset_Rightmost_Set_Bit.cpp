#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int unsetRightmostSetBit(int n)
    {
        return (n&(n - 1));
    }
};