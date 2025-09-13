#include <bits/stdc++.h>
using namespace std;

//floor of x is the largest element in arr[] which is smaller than or equal to x

int floor(vector<int>& arr, int x)
{
    int left = 0;
    int right = arr.size() - 1;
    int ans = -1;
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(arr[mid] <= x)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}

//ceil of x is the smallest element in arr[] which is greater than or equal to x

int ceil(vector<int>& arr, int x)
{
    int left = 0;
    int right = arr.size() - 1;
    int ans = -1;
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(arr[mid] >= x)
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