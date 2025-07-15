#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if(n <= 0)
        {
            return false;
        }
        if(1<<((int)log2(n)) == n)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};