#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int n = nums.size();
        int reach = 1;
        for(int i = 0;i < n;i++)
        {
            if(reach >= i + 1)
            {
                reach = max(reach,nums[i] + i + 1);
            }
        }
        if(reach < n)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};