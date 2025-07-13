#include <bits/stdc++.h>
using namespace std;


class Solution
{
private:
    int timer = 1;
    void DFS(int node,int parent,vector<int>& visited,vector<int> graph[],int t_in[],int low[],vector<vector<int>>& bridges)
    {
        visited[node] = 1;
        t_in[node] = low[node] = timer;
        timer++;
        for(auto item : graph[node])
        {
            if(item == parent)
            {
                continue;
            }
            if(!visited[item])
            {
                DFS(item,node,visited,graph,t_in,low,bridges);
                low[node] = min(low[node],low[item]);
                // check if this node is a bridge
                if(low[item] > t_in[node])
                {
                    bridges.push_back({node,item});
                }
            }
            else
            {
                low[node] = min(low[node],low[item]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections)
    {
        vector<int> graph[n];
        for(auto item : connections)
        {
            graph[item[0]].push_back(item[1]);
            graph[item[1]].push_back(item[0]);
        }
        vector<int> visited(n,0);
        int t_in[n];
        int low[n];
        vector<vector<int>> bridges;
        DFS(0,-1,visited,graph,t_in,low,bridges);
        return bridges;
    }
};