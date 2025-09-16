#include <bits/stdc++.h>
using namespace std;

int findPages(vector<int>& arr,int k)
{
    int n = arr.size();
    if(k > n)
    {
        return -1;
    }
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    int ans = -1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        int studentCount = 1;
        int pageSum = 0;
        for(int i = 0; i < n; i++)
        {
            if(pageSum + arr[i] <= mid)
            {
                pageSum += arr[i];
            }
            else
            {
                studentCount++;
                if(studentCount > k || arr[i] > mid)
                {
                    break;
                }
                pageSum = arr[i];
            }
        }
        if(studentCount == k)
        {
            ans = mid;
            high = mid - 1;
        }
        else if(studentCount < k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}