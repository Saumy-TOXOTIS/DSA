#include "template.hpp"
ll n, m;
const ll N = 2e5;
v(ll) graph[N + 1];
v(ll) visited(N + 1,0);
queue<pair<ll,ll>> q;

/*########### Extra Functions ###########*/

// void BFS(ll start)
// {
//     cout<<start<<" ";
//     q.push(start);
//     while(!q.empty())
//     {
//         ll current = q.front();
//         visited[current] = 1;
//         q.pop();
//         for(auto item : graph[current])
//         {
//             if(!visited[item])
//             {
//                 q.push(item);
//             }
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

        graph[U].push_back(V);
        graph[V].push_back(U); // no need for this if graph was directed
    }
    d_ll(start)
    bool cycle = false;
    function<void(ll,ll)> BFS;
    BFS = [&](ll start,ll parent)
    {
        q.push({start,parent});
        while(!q.empty())
        {
            ll current = q.front().F;
            ll par = q.front().S;
            visited[current] = 1;
            q.pop();
            for(auto item : graph[current])
            {
                if(!visited[item])
                {
                    q.push({item,current});
                }
                elif(item != par)
                {
                    cycle = true;
                }
            }
        }
    };
    cout<<endl;
}