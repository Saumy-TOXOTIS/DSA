#include <bits/stdc++.h>
using namespace std;
int dr[] = {1,0,-1,0,1,-1,1,-1};
int dc[] = {0,1,0,-1,1,-1,-1,1};

//answer is number of visited nodes in the path and also you can visit a node if and only if its cell value is 0

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        {
            return -1;
        }
        if(n == 1)
        {
            return 1;
        }
        queue<tuple<int,int,int>> pq;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        int s_row = 0, s_col = 0;
        dist[s_row][s_col] = 1;
        if(grid[s_row][s_col] == 0)
        {
            pq.push({dist[s_row][s_col],s_row,s_col});
        }
        while(!pq.empty())
        {
            auto item = pq.front();
            int cur_dist = get<0>(item);
            int row = get<1>(item);
            int col = get<2>(item);
            pq.pop();
            for(int i = 0;i < 8;i++)
            {
                int n_row = row + dr[i];
                int n_col = col + dc[i];
                if(n_row >= 0 && n_row < n && n_col >= 0 && n_col < n && grid[n_row][n_col] == 0)
                {
                    if(dist[n_row][n_col] > cur_dist + 1)
                    {
                        dist[n_row][n_col] = cur_dist + 1;
                        pq.push({dist[n_row][n_col],n_row,n_col});
                        if(n_row == n - 1 && n_col == n - 1)
                        {
                            return dist[n_row][n_col];
                        }
                    }
                }
            }
        }
        for(auto item : dist)
        {
            for(auto elem : item)
            {
                cout<<elem<<" ";
            }
            cout<<endl;
        }
        return -1;
    }
};