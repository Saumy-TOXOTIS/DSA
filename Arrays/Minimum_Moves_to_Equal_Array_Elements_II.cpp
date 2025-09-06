#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMoves2(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        int ans = 0;
        for (int num : nums) {
            ans += abs(num - median);
        }
        return ans;
    }
};