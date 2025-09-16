#include <bits/stdc++.h>
using namespace std;

int minDays(vector<int>& bloomDay,int m,int k)
{
    int n = bloomDay.size();
    if((long)m*k > n)
    {
        return -1;
    }
    int start = 1;
    int end = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = -1;
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        int count = 0;
        int bouquet = 0;
        for(int i = 0;i < n;i++)
        {
            if(bloomDay[i] <= mid)
            {
                count++;
                if(count == k)
                {
                    bouquet++;
                    count = 0;
                }
            }
            else
            {
                count = 0;
            }
        }
        if(bouquet >= m)
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