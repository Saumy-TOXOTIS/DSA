#include <bits/stdc++.h>
using namespace std;

int findRoot(int n)
{
    int start = 0;
    int end = n;
    int ans = -1;
    while(start <= end)
    {
        int mid =  start + (end - start)/2;
        if((mid*mid) == n)
        {
            ans = mid;
            break;
        }
        else if((mid*mid) < n)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}