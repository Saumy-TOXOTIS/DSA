#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
        int n = equations.size();
        map<string,vector<pair<string,double>>> graph;
        for (int i = 0;i < n;++i)
        {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            graph[a].emplace_back(b,val);
            graph[b].emplace_back(a,1.0/val);
        }
        vector<double> res;
        for(auto& query : queries)
        {
            string a = query[0];
            string b = query[1];
            double ans = -1.0;
            if(graph.count(a) && graph.count(b))
            {
                map<string,bool> visited;
                function<void(string,double)> dfs = [&](string u,double val)
                {
                    if(u == b)
                    {
                        ans = val;
                        return;
                    }
                    visited[u] = true;
                    for(auto& [v,weight] : graph[u])
                    {
                        if(!visited[v])
                        {
                            dfs(v,val*weight);
                        }
                    }
                };
                dfs(a,1.0);
            }
            res.push_back(ans);
        }
        return res;
    }
};