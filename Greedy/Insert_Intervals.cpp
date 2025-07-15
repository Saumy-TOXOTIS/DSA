#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,vector<int>& newInterval)
    {
        vector<vector<int>> result;
        int n = intervals.size();
        int i = 0;
        // Storing Left Isolated Portion
        while(i < n && intervals[i][1] < newInterval[0])
        {
            result.push_back(intervals[i]);
            i++;
        }
        // Storing Middle Overlapping Portion
        while(i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0],intervals[i][0]);
            newInterval[1] = max(newInterval[1],intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);
        // Storing Right Isolated Portion
        while(i < n)
        {
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};