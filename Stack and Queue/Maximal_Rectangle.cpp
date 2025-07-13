#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
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
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> prefixHeight(row,vector<int>(col,0));
        for(int i = 0;i < col;i++)
        {
            prefixHeight[0][i] = matrix[0][i] - '0';
        }
        for(int j = 0;j < col;j++)
        {
            for(int i = 1;i < row;i++)
            {
                if(matrix[i][j] == '0')
                {
                    prefixHeight[i][j] = 0;
                }
                else
                {
                    prefixHeight[i][j] = prefixHeight[i - 1][j] + matrix[i][j] - '0';
                }
            }
        }
        int maxArea = -1;
        for(int i = 0;i < row;i++)
        {
            maxArea = max(maxArea,largestRectangleArea(prefixHeight[i]));
        }
        return maxArea;
    }
};