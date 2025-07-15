#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int setRightmostUnsetBit(int n)
    {
        return (n|(n + 1));
    }
};