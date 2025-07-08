#include "template.hpp"
ll n, m;
const ll N = 2e5;
v(ll) graph[N + 1];
v(ll) visited(N + 1,0);
v(ll) path(N + 1,0);
v(ll) check(N + 1,0);
v(ll) indegree(N + 1,0);
queue<ll> q;

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

/*################ Code #################*/

TOXOTIS
{
    // Fast_IO
    cin>>n>>m;
    f1(i,0,m,1)
    {
        d_ll(U) d_ll(V)
        graph[U].push_back(V);
        indegree[V]++;
    }
    f1(i,1,n + 1,1)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }
    v(ll) topo_sort;
    while(!q.empty())
    {
        ll current = q.front();
        topo_sort.push_back(current);
        q.pop();
        for(auto item : graph[current])
        {
            indegree[item]--;
            if(indegree[item] == 0)
            {
                q.push(item);
            }
        }
    }
    for(auto item : topo_sort)
    {
        cout<<item<<" ";
    }
    cout<<endl;
}