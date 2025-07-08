#include "template.hpp"
ll n, m;
const ll N = 2e5;
v(v(ll)) graph(N + 1,v(ll)(N + 1,0));
v(v(ll)) visited(N + 1,v(ll)(N + 1,0));
v(ll) dx = {1,-1,1,-1,0,0,1,-1};
v(ll) dy = {1,-1,-1,1,1,-1,0,0};
queue<ll> q;

/*########### Extra Functions ###########*/

// void DFS(ll row,ll col)
// {
//     visited[row][col] = 1;
//     for (ll i = 0; i < 8; i++)
//     {
//         ll new_row = row + dy[i];
//         ll new_col = col + dx[i];
//         if ((new_row > 0) && (new_row <= n) && (new_col > 0) && (new_col <= n) && (graph[new_row][new_col]) && (!visited[new_row][new_col]))
//         {
//             DFS(new_row, new_col);
//         }
//     }
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
    function<void(ll,ll)> DFS;
    DFS = [&](ll row,ll col)
    {
        visited[row][col] = 1;
        for(ll i = 0;i < 8;i++)
        {
            ll new_row = row + dy[i];
            ll new_col = col + dx[i];
            if((new_row > 0) && (new_row <= n) && (new_col > 0) && (new_col <= n) && (graph[new_row][new_col]) && (!visited[new_row][new_col]))
            {
                DFS(new_row,new_col);
            }
        }
    };
    ll islands = 0;
    f1(i,0,n,1)
    {
        f1(j,0,n,1)
        {
            if((graph[i][j]) && (!visited[i][j]))
            {
                islands++;
                DFS(i,j);
            }
        }
    }
    cout<<"Number of Islands : "<<islands<<endl;
}