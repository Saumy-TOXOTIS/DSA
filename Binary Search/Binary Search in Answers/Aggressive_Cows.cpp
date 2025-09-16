#include <bits/stdc++.h>
using namespace std;

int aggressiveCows(int n,int k,vector<int>& stalls)
{
    sort(stalls.begin(),stalls.end());
    int low = 1;
    int high = stalls[n-1] - stalls[0];
    int ans = -1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        int count = 1;
        int lastPos = stalls[0];
        for(int i = 0;i < n;i++)
        {
            if(stalls[i] - lastPos >= mid)
            {
                count++;
                lastPos = stalls[i];
            }
        }
        if(count >= k)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}