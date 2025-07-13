#include <bits/stdc++.h>
using namespace std;

// We can trap water on a building if and only if there is a building that is having greater height than that one either on left or on right and water stored for that building will be minimum height of both buildings having height greater than that building minus heght of that building

class Solution
{
public:
    int trap(vector<int>& height)
    {
        int n = height.size();
        int water = 0;
        vector<int> suffMax(n);
        int lefMax = -1;
        suffMax[n - 1] = height[n - 1];
        for(int i = n - 2;i >= 0;i--)
        {
            suffMax[i] = max(suffMax[i + 1],height[i]);
        }
        function<int(int)> Relu;
        Relu = [&](int val)
        {
            if(val <= 0)
            {
                return 0;
            }
            else
            {
                return val;
            }
        };
        for(int i = 0;i < n;i++)
        {
            lefMax = max(lefMax,height[i]);
            int minHeight = min(lefMax,suffMax[i]);
            water += Relu(minHeight - height[i]);
        }
        return water;
    }
};