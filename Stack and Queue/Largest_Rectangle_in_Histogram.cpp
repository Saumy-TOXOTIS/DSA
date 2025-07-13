#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size();
        vector<int> nse(n,n);
        vector<int> psee(n,-1);
        stack<int> s;
        for(int i = 0;i < n;i++)
        {
            while(!s.empty() && heights[s.top()] > heights[i])
            {
                nse[s.top()] = i;
                s.pop();
            }
            if(!s.empty())
            {
                psee[i] = s.top();
            }
            s.push(i);
        }
        int maxArea = -1;
        for(int i = 0;i < n;i++)
        {
            int width = nse[i] - psee[i] - 1;
            maxArea = max(maxArea,heights[i]*width);
        }
        return maxArea;
    }
};