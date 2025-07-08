#include "template.hpp"
v(ll) dx = {0,0,1,-1};
v(ll) dy = {1,-1,0,0};

TOXOTIS
{
    Fast_IO
    d_ll(n) d_ll(m)
    v(v(ll)) graph(n + 1,v(ll)(m + 1,0));
    queue<pair<ll,ll>> q;
    v(v(ll)) answer(n + 1,v(ll)(m + 1,-1));
    f1(i,1,n + 1,1)
    {
        f1(j,1,m + 1,1)
        {
            cin>>graph[i][j];
            if(graph[i][j] == 1)
            {
                q.push({i,j});
                answer[i][j] = 0;
            }
        }
    }
    while(!q.empty())
    {
        ll r = q.front().F;
        ll c = q.front().S;
        q.pop();
        for(ll i = 0;i < 4;i++)
        {
            ll new_r = r + dy[i];
            ll new_c = c + dx[i];
            if(new_r > 0 && new_r <= n && new_c > 0 && new_c <= m && answer[new_r][new_c] == -1)
            {
                answer[new_r][new_c] = answer[r][c] + 1;
                q.push({new_r,new_c});
            }
        }
    }
    cout<<endl;
    f1(i,1,n + 1,1)
    {
        f1(j,1,m + 1,1)
        {
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }
}