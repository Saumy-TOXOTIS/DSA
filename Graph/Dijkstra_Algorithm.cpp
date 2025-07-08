#include "template.hpp"
ll n, m, source, destination;
const ll N = 2e5 + 1;
vector<pair<ll,ll>> graph[N + 1];
v(ll) visited(N + 1,0);
v(ll) path(N + 1,0);
v(ll) check(N + 1,0);
v(ll) indegree(N + 1,0);
v(ll) dist(N + 1,lMAX);
v(ll) parent(N + 1,0);
queue<ll> q;
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq; //{dist,node}
set<pair<ll,ll>> s; //{dist,node}

/*########### Extra Functions ###########*/

//Dijkstra don't work with graph having negative weights

//Using Priority Queue
void Dijkstra_Algorithm_pq()
{
    while(!pq.empty())
    {
        ll cur_dist = pq.top().first;
        ll cur_node = pq.top().second;
        pq.pop();
        for(auto item : graph[cur_node])
        {
            ll node = item.first;
            ll weight = item.second;
            if(dist[node] > (cur_dist + weight))
            {
                parent[node] = cur_node; //path memoisation, where it came from who is its parent and thats how it will keep track of path of shortest distance from a source node
                dist[node] = cur_dist + weight;
                pq.push({dist[node],node});
            }
        }
    }
}

//Using Set
void Dijkstra_Algorithm_set()
{
    while(!s.empty())
    {
        ll cur_dist = (*s.begin()).first;
        ll cur_node = (*s.begin()).second ;
        s.erase(s.begin());
        for(auto item : graph[cur_node])
        {
            ll node = item.first;
            ll weight = item.second;
            if(dist[node] > (cur_dist + weight))
            {
                parent[node] = cur_node; //path memoisation, where it came from who is its parent and thats how it will keep track of path of shortest distance from a source node
                dist[node] = cur_dist + weight;
                s.insert({dist[node],node});
            }
        }
    }
}

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
    cin>>source>>destination;
    f1(i,1,n + 1,1)
    {
        parent[i] = i;
    }
    dist[source] = 0;
    pq.push({0,source});
    Dijkstra_Algorithm_pq();
    s.insert({0,source});
    Dijkstra_Algorithm_set();
    v(ll) ans;
    while(parent[destination] != destination)
    {
        ans.push_back(destination);
        destination = parent[destination];
    }
    reverse(all(ans));
    //shortes path
    for(auto item : ans)
    {
        cout<<item<<" ";
    }
    cout<<endl;
    //length
    cout<<dist[destination]<<endl;
}