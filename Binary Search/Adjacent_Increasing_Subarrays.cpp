#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxIncreasingSubarrays(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> L(n,1);
        vector<int> R(n,1);
        for(int i = 1;i < n;i++)
        {
            if(nums[i] > nums[i - 1])
            {
                L[i] = L[i - 1] + 1;
            }
        }
        for(int i = n - 2;i >= 0;i--)
        {
            if(nums[i] < nums[i + 1])
            {
                R[i] = R[i + 1] + 1;
            }
        }
        int low = 1;
        int high = n/2;
        int ans = high;
        bool flag = false;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            flag = false;
            for(int i = 0;i < n - 1;i++)
            {
                if(L[i] >= mid && R[i + 1] >= mid)
                {
                    ans = mid;
                    low = mid + 1;
                    flag = true;
                    break;
                }
            }
            if(!flag)
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};