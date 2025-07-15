#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPlatform(vector<int>& Arrival,vector<int>& Departure)
    {
        int n = Arrival.size();
        sort(Arrival.begin(),Arrival.end());
        sort(Departure.begin(),Departure.end());
        int i = 0; // For Arrival
        int j = 0; // For Departure
        int c = 0;
        int ans = 0;
        while(i < n)
        {
            if(Arrival[i] <= Departure[j])
            {
                c++;
                i++;
            }
            else
            {
                c--;
                j++;
            }
            ans = max(ans,c);
        }
        return ans;
    }
};