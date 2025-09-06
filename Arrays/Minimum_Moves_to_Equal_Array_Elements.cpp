#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMoves(vector<int>& nums)
    {
        int minElem = *min_element(nums.begin(),nums.end());
        int ans = 0;
        for(auto item : nums)
        {
            ans += item - minElem;
        }
        return ans;
    }
};