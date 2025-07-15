#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int averageWaitingTime(vector<int>& executionTime)
    {
        int n = executionTime.size();
        sort(executionTime.begin(),executionTime.end());
        int waitingTillNow = 0;
        int totalWaitingTime = 0;
        for(int i = 1;i < n;i++)
        {
            waitingTillNow += executionTime[i - 1];
            totalWaitingTime += waitingTillNow;
        }
        return totalWaitingTime/n;
    }
};