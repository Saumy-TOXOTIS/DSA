#include <bits/stdc++.h>
using namespace std;

// array - [1,8,6,2,5,4,8,3,7]

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int n = height.size();
        int i = 0;
        int j = n - 1;
        int ans = 0;
        while(i < j)
        {
            int left = height[i];
            int right = height[j];
            ans = max(ans,min(left,right)*(j - i));
            if(left < right)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return ans;
    }
};