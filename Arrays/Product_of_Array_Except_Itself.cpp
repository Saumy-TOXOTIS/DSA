#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = static_cast<int>(nums.size());
        vector<int> result(n, 1);
        long long prefix = 1;
        for (int i = 0; i < n; i++)
        {
            result[i] = static_cast<int>(prefix);
            prefix *= nums[i];
        }
        long long suffix = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            result[i] = static_cast<int>(result[i] * suffix);
            suffix *= nums[i];
        }
        return result;
    }
};
