#include "template.hpp"
ll n, m, new_color, color;
const ll N = 2e5;
v(v(ll)) graph(N + 1,v(ll)(N + 1,0));
v(v(ll)) visited(N + 1,v(ll)(N + 1,0));
v(ll) dx = {0,0,1,-1};
v(ll) dy = {1,-1,0,0};
queue<ll> q;

/*########### Extra Functions ###########*/

// void DFS(ll sr,ll sc)
// {
//     visited[sr][sc] = 1;
//         graph[sr][sc] = new_color;
//         for(ll i = 0;i < 4;i++)
//         {
//             ll new_row = sr + dy[i];
//             ll new_col = sc + dx[i];
//             if((new_row > 0) && (new_row <= n) && (new_col > 0) && (new_col <= n) && (graph[new_row][new_col] == color) && (!visited[new_row][new_col]))
//             {
//                 DFS(new_row,new_col);
//             }
//         }
// }

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

        graph[U][V] = 1;
        graph[V][U] = 1; // no need for this if graph was directed
    }
    d_ll(sr) d_ll(sc)
    color = graph[sr][sc];
    cin>>new_color;
    function<void(ll,ll)> DFS;
    DFS = [&](ll sr,ll sc)
    {
        visited[sr][sc] = 1;
        graph[sr][sc] = new_color;
        for(ll i = 0;i < 4;i++)
        {
            ll new_row = sr + dy[i];
            ll new_col = sc + dx[i];
            if((new_row > 0) && (new_row <= n) && (new_col > 0) && (new_col <= n) && (graph[new_row][new_col] == color) && (!visited[new_row][new_col]))
            {
                DFS(new_row,new_col);
            }
        }
    };
    DFS(sr,sc);
}