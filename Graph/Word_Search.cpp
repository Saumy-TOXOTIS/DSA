#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>>& board,string word)
    {
        int n = board.size();
        int m = board[0].size();
        int dr[] = {1,0,-1,0};
        int dc[] = {0,1,0,-1};
        queue<pair<int,int>> q;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(board[i][j] == word[0])
                {
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            auto [i,j] = q.front();
            q.pop();
            vector<vector<int>> visited(n,vector<int>(m,0));
            function<bool(int,int,int)> DFS;
            DFS = [&](int i,int j,int index)
            {
                if(index == word.length())
                {
                    return true;
                }
                if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[index] || visited[i][j])
                {
                    return false;
                }
                visited[i][j] = 1;
                for(int idx = 0;idx < 4;idx++)
                {
                    int ni = i + dr[idx];
                    int nj = j + dc[idx];
                    if(DFS(ni,nj,index + 1))
                    {
                        return true;
                    }
                }
                visited[i][j] = 0;
                return false;
            };
            if(DFS(i,j,0))
            {
                return true;
            }
        }
        return false;
    }
};