#include <bits/stdc++.h>
using namespace std;

/*
You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.
*/

class Solution
{
public:
    int countPaths(int n, vector<vector<int>>& roads)
    {
        int M = 1e9 + 7;
        int src = 0;
        int dst = n - 1;
        vector<pair<int,int>> graph[n];
        vector<int> ways(n,0);
        vector<long long> dist(n,1e12);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq; // dist,src
        for(auto item : roads)
        {
            int u = item[0];
            int v = item[1];
            int w = item[2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        ways[src] = 1;
        dist[src] = 0;
        pq.push({dist[src],src});
        while(!pq.empty())
        {
            long long cur_dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto item : graph[node])
            {
                int child = item.first;
                int weight = item.second;
                long long newCost = cur_dist + weight + 0LL;
                if(newCost < dist[child])
                {
                    ways[child] = ways[node];
                    dist[child] = newCost;
                    pq.push({newCost,child});
                }
                else if(dist[child] == newCost)
                {
                    ways[child] = (ways[child] + ways[node])%M;
                }
            }
        }
        return ways[dst]%M;
    }
};