#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:  
    vector<int> JobScheduling(vector<vector<int>>& Jobs)
    { 
        sort(Jobs.begin(),Jobs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2];
        });
        int count = 0;
        int maxProfit = 0;
        int maxDeadline = 0;
        for(auto item : Jobs)
        {
            maxDeadline = max(maxDeadline,item[1]);
        }
        vector<int> jobScheduled(maxDeadline + 1,-1);
        for(auto item : Jobs)
        {
            int jobId = item[0];
            int curDeadling = item[1];
            int curProfit = item[2];
            while(jobScheduled[curDeadling] != -1)
            {
                curDeadling--;
            }
            if(curDeadling >= 0)
            {
                jobScheduled[curDeadling] = jobId;
                maxProfit += curProfit;
                count++;
            }
        }
        return {count,maxProfit};
    } 
};