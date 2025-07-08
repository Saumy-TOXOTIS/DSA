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
        d_ll(U) d_ll(V)
        graph[U].push_back({V,1});
        indegree[V]++;
    }
    cin>>source;
    dist[source] = 0;
    q.push(source);
    while(!q.empty())
    {
        ll cur = q.front();
        visited[cur] = 1;
        q.pop();
        for(auto item : graph[cur])
        {
            dist[item.first] = min(dist[item.first],dist[cur] + item.second);
            if(!visited[item.first])
            {
                q.push(item.first);
            }
        }
    }
    f1(i,0,n,1)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}