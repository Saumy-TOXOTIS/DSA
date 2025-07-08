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
priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>> pq; //{weight,node,parent}
vector<tuple<ll,ll,ll>> MST;

/*########### Extra Functions ###########*/

/*
MST -> Minimum Spanning Tree
Spanning Tree -> A tree in which we have n nodes and (n - 1) edges and all nodes are reachable from each other
Minimum Spanning Tree -> A Spanning Tree with least/minimum sum of all the edge weights
*/

/*################ Code #################*/

TOXOTIS
{
    // Fast_IO
    cin>>n>>m;
    f1(i,0,m,1)
    {
        d_ll(U) d_ll(V) d_ll(W)
        graph[U].push_back({V,W});
        graph[V].push_back({U,W});
    }
    pq.push({0,0,-1});
    ll mst_weight_sum = 0;
    while(!pq.empty())
    {
        auto item = pq.top();
        pq.pop();
        ll weight = get<0>(item);
        ll node = get<1>(item);
        ll parent = get<2>(item);
        if(visited[node])
        {
            continue;
        }
        visited[node] = 1;
        mst_weight_sum += weight;
        MST.push_back({parent,node,weight});
        for(auto elem : graph[node])
        {
            ll child = elem.first;
            ll edge_weight = elem.second;
            if(!visited[child])
            {
                pq.push({edge_weight,child,node});
            }
        }
    }
}