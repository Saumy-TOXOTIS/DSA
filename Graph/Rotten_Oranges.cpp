#include "template.hpp"

const ll N = 2e5;
v(ll) dx = {0,0,1,-1};
v(ll) dy = {1,-1,0,0};

/*########### Extra Functions ###########*/

/*################ Code #################*/

TOXOTIS
{
    // Fast_IO
    d_ll(n) d_ll(m)
    v(v(ll)) graph(n + 1,v(ll)(m + 1,0));
    v(v(ll)) visited(n + 1,v(ll)(m + 1,0));
    queue<pair<pair<ll,ll>,ll>> q;
    f1(i,1,n + 1,1)
    {
        f1(j,1,m + 1,1)
        {
            cin>>graph[i][j];
            visited[i][j] = 0;
            if(graph[i][j] == 2)
            {
                q.push({{i,j},0});
            }
        }
    }
    cout<<q.size()<<endl;
    ll times = 0;
    while(!q.empty())
    {
        ll cur_row = q.front().F.F;
        ll cur_col = q.front().F.S;
        ll cur_time = q.front().S;
        cout<<cur_row<<" "<<cur_col<<endl;
        visited[cur_row][cur_col] = 1;
        q.pop();
        for(ll i = 0;i < 4;i++)
        {
            ll new_row = cur_row + dy[i];
            ll new_col = cur_col + dx[i];
            if((new_row > 0) && (new_row <= n) && (new_col > 0) && (new_col <= m) && (graph[new_row][new_col] == 1) && (!visited[new_row][new_col]))
            {
                graph[new_row][new_col] = 2;
                times = max(times,cur_time + 1);
                q.push({{new_row,new_col},cur_time + 1});
            }
        }
    }
    cout<<"Total time to rott : "<<times<<endl;
}