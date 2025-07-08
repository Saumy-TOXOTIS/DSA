#include "template.hpp"
ll n, m, source;
const ll N = 2e5;
vector<pair<ll,ll>> graph[N + 1];
v(ll) visited(N + 1,0);
v(ll) path(N + 1,0);
v(ll) dist(N + 1,lMAX);
v(ll) indegree(N + 1,0);
queue<ll> q;

/*########### Extra Functions ###########*/

/*################ Code #################*/

TOXOTIS
{
    // Fast_IO
    cin>>n>>m;
    f1(i,0,m,1)
    {
        d_ll(U) d_ll(V) d_ll(W)
        graph[U].push_back({V,W});
        indegree[V]++;
    }
    cin>>source;
    dist[source] = 0;
    f1(i,0,n,1)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        ll cur = q.front();
        q.pop();
        for(auto item : graph[cur])
        {
            indegree[item.first]--;
            if(dist[cur] != lMAX)
            {
                dist[item.first] = min(dist[item.first],dist[cur] + item.second);
            }
            //relaxation of edges
            if(indegree[item.first] == 0)
            {
                q.push(item.first);
            }
        }
    }
    // q.push(source);
    // while(!q.empty())
    // {
    //     ll cur = q.front();
    //     visited[cur] = 1;
    //     q.pop();
    //     for(auto item : graph[cur])
    //     {
    //         dist[item.first] = min(dist[item.first],dist[cur] + item.second);
    //         if(!visited[item.first])
    //         {
    //             q.push(item.first);
    //         }
    //     }
    // }
    f1(i,0,n,1)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}