#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int celebrity(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0;
        int down = n - 1;
        while(top < down)
        {
            if(matrix[top][down] == 1)
            {
                // top knows down it means top isn't a celeb
                top++;
            }
            else if(matrix[down][top] == 1)
            {
                // down knows top it mean down isn't a celeb
                down--;
            }
            else
            {
                // both doesn't know each other it mean both aren't a celeb
                top++;
                down--;
            }
        }
        if(top > down)
        {
            return -1;
        }
        else
        {
            bool isCeleb = true;
            for(int i = 0;i < m;i++)
            {
                if(matrix[top][i] == 1)
                {
                    // if top knows at least one person it means top isn't a celeb
                    isCeleb = false;
                    break;
                }
            }
            for(int i = 0;i < n;i++)
            {
                if(i == top)
                {
                    // top can't know itself
                    continue;
                }
                if(matrix[i][top] == 0)
                {
                    // if top doesn't known by at least one person it means top isn't a celeb
                    isCeleb = false;
                    break;
                }
            }
            if(isCeleb)
            {
                return top;
            }
            else
            {
                return -1;
            }
        }
    }
};