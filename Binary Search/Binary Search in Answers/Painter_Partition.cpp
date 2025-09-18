#include <bits/stdc++.h>
using namespace std;

int minimizeTime(vector<int>& arr,int k)
{
    int n = arr.size();
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    int ans = high;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        int painters = 1;
        int currSum = 0;
        for(int i = 0;i < n;i++)
        {
            if(arr[i] > mid)
            {
                break;
            }
            if(currSum + arr[i] > mid)
            {
                painters++;
                currSum = arr[i];
            }
            else
            {
                currSum += arr[i];
            }
        }
        if(painters <= k)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}