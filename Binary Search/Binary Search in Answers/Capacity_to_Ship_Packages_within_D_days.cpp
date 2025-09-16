#include <bits/stdc++.h>
using namespace std;

int shipWithinDays(vector<int>& weights,int days)
{
    int n = weights.size();
    int start = *max_element(weights.begin(),weights.end());
    int end = accumulate(weights.begin(),weights.end(),0);
    int ans = end;
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        int currSum = 0;
        int currDays = 1;
        for(int i = 0;i < n;i++)
        {
            currSum += weights[i];
            if(currSum > mid)
            {
                currDays++;
                currSum = weights[i];
            }
        }
        if(currDays <= days)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}