#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        vector<pair<int,int>> graph[n];
        for(auto item : flights)
        {
            int u = item[0];
            int v = item[1];
            int w = item[2];
            graph[u].push_back({v,w});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,1e9);
        dist[src] = 0;
        q.push({0,{src,dist[src]}});
        while(!q.empty())
        {
            auto item = q.front();
            q.pop();
            int cur_stop = item.first;
            int node = item.second.first;
            int cur_dist = item.second.second;
            if(cur_stop == k + 1)
            {
                continue;
            }
            for(auto item : graph[node])
            {
                int child = item.first;
                int weight = item.second;
                if(dist[child] > weight + cur_dist)
                {
                    dist[child] = weight + cur_dist;
                    q.push({cur_stop + 1,{child,dist[child]}});
                }
            }
        }
        if(dist[dst] == 1e9)
        {
            return -1;
        }
        else
        {
            return dist[dst];
        }
    }
};