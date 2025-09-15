#include <bits/stdc++.h>
using namespace std;

//lower_bound function returns the index of the first element which is greater than or equal to target
int lower_bound(vector<int>& arr,int target)
{
    int left = 0;
    int right = arr.size() - 1;
    int ans = arr.size();
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(arr[mid] >= target)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}

//upper_bound function returns the index of the first element which is greater than target
int upper_bound(vector<int>& arr,int target)
{
    int left = 0;
    int right = arr.size() - 1;
    int ans = arr.size();
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(arr[mid] <= target)
        {
            left = mid + 1;
        }
        else
        {
            ans = mid;
            right = mid - 1;
        }
    }
    return ans;
}