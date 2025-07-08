#include "template.hpp"
ll n, m;
const ll N = 2e5;
v(ll) graph[N + 1];
v(ll) visited(N + 1,0);

/*########### Extra Functions ###########*/

void DFS(ll start)
{
    cout<<start<<" ";
    visited[start] = 1;
    for(auto item : graph[start])
    {
        if(!visited[item])
        {
            DFS(item);
        }
    }
}

/*################ Code #################*/

TOXOTIS
{
    // Fast_IO
    cin>>n>>m;
    v(v(ll)) graph_1(n + 1,v(ll)(n + 1,0));
    v(ll) graph_2[n + 1];
    f1(i,0,m,1)
    {
        d_ll(U) d_ll(V)
        /*
        if undirected then edge will be both u->v and v->u
        if directed then edge will be u->v
        */
        //Method 1 : Storing in Matrix ( Adjacency Matrix )
        graph_1[U][V] = 1;
        graph_1[V][U] = 1; // no need for this if graph was directed
        //Method 2 : Storing in list ( Adjacency List )
        graph_2[U].push_back(V);
        graph_2[V].push_back(U); // no need for this if graph was directed

        graph[U].push_back(V);
        graph[V].push_back(U); // no need for this if graph was directed
    }
    d_ll(start)
    DFS(start);
    cout<<endl;
}