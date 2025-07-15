#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int a = intervals[0][0];
        int b = intervals[0][1];
        int n = intervals.size();
        for(int i = 1;i < n;i++)
        {
            int fst = intervals[i][0];
            int lst = intervals[i][1];
            if(a <= fst && fst < b)
            {
                b = max(b,lst);
            }
            else if(fst == b)
            {
                b = lst;
            }
            else
            {
                vector<int> dummy;
                dummy.push_back(a);
                dummy.push_back(b);
                ans.push_back(dummy);
                a = fst;
                b = lst;
            }
        }
        vector<int> dummy;
        dummy.push_back(a);
        dummy.push_back(b);
        ans.push_back(dummy);
        return ans;
    }
};