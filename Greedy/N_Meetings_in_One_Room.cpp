#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool compare(tuple<int,int,int>& a,tuple<int,int,int>& b)
    {
        int A = get<1>(a);
        int B = get<1>(b);
        return (A < B);
    }
public:
    int maxMeetings(vector<int>& start,vector<int>& end)
    {
        int n = start.size();
        vector<tuple<int,int,int>> details;
        for(int i = 0;i < n;i++)
        {
            details.push_back({start[i],end[i],(i + 1)});
        }
        sort(details.begin(),details.end(),compare);
        vector<int> meetingOrder;
        int count = 0;
        int nextTime = 0;
        for(auto item : details)
        {
            int s = get<0>(item);
            int e = get<1>(item);
            int p = get<2>(item);
            if(s >= nextTime)
            {
                count++;
                meetingOrder.push_back(p);
                nextTime = e;
            }
        }
        return count;
    }
};