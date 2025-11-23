#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, source, destination;
const ll N = 2e5 + 1;
vector<pair<ll,ll>> graph[N + 1];
vector<ll> visited(N + 1,0);
vector<ll> path(N + 1,0);
vector<ll> check(N + 1,0);
vector<ll> indegree(N + 1,0);
vector<ll> dist(N + 1,1e9);
vector<ll> parent(N + 1,0);
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

int main()
{
    cin>>n>>m;
    vector<tuple<ll,ll,ll>> edges;
    for(int i = 0;i < m;i++)
    {
        ll U,V,W;
        cin>>U>>V>>W;
        graph[U].push_back({V,W});
        edges.push_back({U,V,W});
    }
    cin>>source>>destination;
    dist[source] = 0;
    bool negative_cycle = false;
    for(int i = 1;i <= n - 1;i++)
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