#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int count = 0;
        int nextFree = -1e9;
        for(auto item : intervals)
        {
            int start = item[0];
            int end = item[1];
            if(start >= nextFree)
            {
                count++;
                nextFree = end;
            }
        }
        return (n - count);
    }
};