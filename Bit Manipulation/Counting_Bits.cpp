#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1);
        for(int i = 0;i <= n;i++)
        {
            int count = 0;
            int temp = i;
            while(temp > 0)
            {
                temp = temp&(temp - 1);
                count++;
            }
            ans[i] = count;
        }
        return ans;
    }
};