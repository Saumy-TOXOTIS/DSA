#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        for(auto item : edges)
        {
            dist[item[0]][item[1]] = item[2];
            dist[item[1]][item[0]] = item[2];
        }
        for(int i = 0;i < n;i++)
        {
            dist[i][i] = 0;
        }
        for(int k = 0;k < n;k++)
        {
            for(int i = 0;i < n;i++)
            {
                for(int j = 0;j < n;j++)
                {
                    if(dist[i][k] == 1e9 || dist[k][j] == 1e9)
                    {
                        continue;
                    }
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
        int count = n;
        int city = -1;
        for(int i = 0;i < n;i++)
        {
            int dummy = 0;
            for(int j = 0;j < n;j++)
            {
                if(dist[i][j] <= distanceThreshold)
                {
                    dummy++;
                }
            }
            if(dummy <= count)
            {
                count = dummy;
                city = i;
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
        return city;
    }
};