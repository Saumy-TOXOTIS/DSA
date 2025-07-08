#include "template.hpp"
ll n, m;
const ll N = 2e5;
v(ll) graph[N + 1];
v(ll) visited(N + 1,0);
v(ll) path(N + 1,0);
v(ll) check(N + 1,0);

/*########### Extra Functions ###########*/

//Topological Sorting - Linear ordering of vertices such that if there exists an edge between u and v then u appears before v in their ordering
//Topological Sorting always possible for DAG ( Directed Acyclic Graphs )

/*
Graph :

6 ----> 1 <---- 5
|               |
V               V
3 ----> 4 ----> 2

Topological Sort :

- 6 5 3 4 2 1
- 5 6 3 4 2 1
*/

void DFS(ll start,stack<ll>& topo_sort)
{
    visited[start] = 1;
    for(auto item : graph[start])
    {
        if(!visited[item])
        {
            DFS(item,topo_sort);
        }
    }
    topo_sort.push(start);
}

/*################ Code #################*/

TOXOTIS
{
    // Fast_IO
    cin>>n>>m;
    f1(i,0,m,1)
    {
        d_ll(U) d_ll(V)
        graph[U].push_back(V);
    }
    stack<ll> topo_sort;
    f1(i,0,n,1)
    {
        if(!visited[i])
        {
            DFS(i,topo_sort);
        }
    }
    v(ll) ans;
    while(!topo_sort.empty())
    {
        ans.push_back(topo_sort.top());
        topo_sort.pop();
    }
    for(auto item : ans)
    {
        cout<<item<<" ";
    }
    cout<<endl;
}