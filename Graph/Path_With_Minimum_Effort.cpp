#include <bits/stdc++.h>
using namespace std;
int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>>& heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        int s_row = 0;
        int s_col = 0;
        dist[s_row][s_col] = 0;
        pq.push({dist[s_row][s_col],{s_row,s_col}});
        while(!pq.empty())
        {
            auto item = pq.top();
            pq.pop();
            int cur_dist = item.first;
            int row = item.second.first;
            int col = item.second.second;
            for(int i = 0;i < 4;i++)
            {
                int n_row = row + dr[i];
                int n_col = col + dc[i];
                if(n_row >= 0 && n_row < n && n_col >= 0 && n_col < m)
                {
                    int new_dist = max(cur_dist, abs(heights[n_row][n_col] - heights[row][col]));
                    if(new_dist < dist[n_row][n_col])
                    {
                        dist[n_row][n_col] = new_dist;
                        pq.push({new_dist,{n_row,n_col}});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};