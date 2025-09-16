#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int>& arr,int k)
{
    int start = 1;
    int end = 2001;
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        int missing = mid - (upper_bound(arr.begin(),arr.end(),mid) - arr.begin());
        if(missing >= k)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return start;
}