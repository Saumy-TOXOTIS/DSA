#include <bits/stdc++.h>
using namespace std;

int minMaxDist(vector<int>& stations,int k)
{
    sort(stations.begin(),stations.end());
    int n = stations.size();
    int low = 1;
    int high = stations[n - 1] - stations[0];
    int ans = high;
    while(low <= high)
    {
        int mid = low + (high  -low)/2;
        int count = 0;
        for(int i = 1;i < n;i++)
        {
            count += (stations[i] - stations[i - 1] - 1)/mid;
            if(count > k)
            {
                break;
            }
        }
        if(count > k)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}