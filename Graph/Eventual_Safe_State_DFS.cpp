#include "template.hpp"
ll n, m;
const ll N = 2e5;
v(ll) graph[N + 1];
v(ll) visited(N + 1,0);
v(ll) path(N + 1,0);
v(ll) check(N + 1,0);

/*########### Extra Functions ###########*/

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
    set<ll> answers;
    function<bool(ll)> DFS;
    DFS = [&](ll start)
    {
        visited[start] = 1;
        path[start] = 1;
        check[start] = 0;
        for(auto item : graph[start])
        {
            if(!visited[item])
            {
                if(DFS(item))
                {
                    check[start] = 0;
                    return true;
                }
            }
            elif(path[item])
            {
                check[start] = 0;
                return true;
            }
        }
        check[start] = 1;
        path[start] = 0;
        return false;
    };
    f1(i,1,n + 1,1)
    {
        if(!visited[i])
        {
            DFS(i);
        }
    }
    cout<<endl;
}