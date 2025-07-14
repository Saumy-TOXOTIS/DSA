#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int numSubarrayWithFreqLessThanEqual(vector<int>& nums,int k)
    {
        if(k < 0)
        {
            return 0;
        }
        int n = nums.size();
        int left = 0;
        int right = 0;
        unordered_map<int,int> freq;
        int curFreq = 0;
        int count = 0;
        while(right < n)
        {
            freq[nums[right]]++;
            while(freq.size() > k)
            {
                freq[nums[left]]--;
                left++;
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums,int k)
    {
        int n = nums.size();
        int l = numSubarrayWithFreqLessThanEqual(nums,k);
        int r = numSubarrayWithFreqLessThanEqual(nums,k - 1);
        return (l - r);
    }
};