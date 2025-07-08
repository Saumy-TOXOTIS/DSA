#include "template.hpp"
ll n, m, source, destination;
const ll N = 2e5 + 1;
vector<pair<ll,ll>> graph[N + 1];
v(ll) visited(N + 1,0);
v(ll) path(N + 1,0);
v(ll) check(N + 1,0);
v(ll) indegree(N + 1,0);
v(ll) dist(N + 1,1e9);
v(ll) parent(N + 1,0);
queue<ll> q;
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq; //{dist,node}
set<pair<ll,ll>> s; //{dist,node}

/*########### Extra Functions ###########*/

//Bellman Ford Algorithm works with negative weights too! and help to detect negative cycles.

//Relax all the edges (n - 1) times sequentially [n - number of nodes]

/*
Relaxation :

if(dist[parent_node] + edge_weight < dist[child_node])
{
dist[child_node] = dist[parent_node] + edge_weight;
}
*/

/*################ Code #################*/

TOXOTIS
{
    // Fast_IO
    cin>>n>>m;
    vector<tuple<ll,ll,ll>> edges;
    f1(i,0,m,1)
    {
        d_ll(U) d_ll(V) d_ll(W)
        graph[U].push_back({V,W});
        edges.push_back({U,V,W});
    }
    cin>>source>>destination;
    dist[source] = 0;
    bool negative_cycle = false;
    f1(i,0,n - 1,1)
    {
        for(auto item : edges)
        {
            ll parent = get<0>(item);
            ll child = get<1>(item);
            ll weight = get<2>(item);
            if(dist[parent] + weight < dist[child])
            {
                dist[child] = dist[parent] + weight;
            }
        }
    }
    //nth relaxation for checking negative cycles
    for(auto item : edges)
    {
        ll parent = get<0>(item);
        ll child = get<1>(item);
        ll weight = get<2>(item);
        if(dist[parent] + weight < dist[child])
        {
            negative_cycle = true;
        }
    }
    if(negative_cycle)
    {
        cout<<"Negative Cycle Detected!"<<endl;
    }
    else
    {
        cout<<dist[destination]<<endl;
    }
}