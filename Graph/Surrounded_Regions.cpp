#include "template.hpp"
v(ll) dx = {0,0,1,-1};
v(ll) dy = {1,-1,0,0};

TOXOTIS
{
    d_ll(n) d_ll(m)
    v(v(char)) graph(n + 1,v(char)(m + 1));
    v(v(char)) answer(n + 1,v(char)(m + 1,'X'));
    queue<pair<ll,ll>> q;
    f1(i,1,n + 1,1)
    {
        f1(j,1,m + 1,1)
        {
            cin>>graph[i][j];
            if(i == 1 || i == n)
            {
                if(graph[i][j] == 'O')
                {
                    q.push({i,j});
                }
            }
            elif(j == 1 || j == m)
            {
                if(graph[i][j] == 'O')
                {
                    q.push({i,j});
                }
            }
        }
    }
    while(!q.empty())
    {
        ll r = q.front().F;
        ll c = q.front().S;
        answer[r][c] = 'O';
        q.pop();
        for(ll i = 0;i < 4;i++)
        {
            ll new_r = r + dy[i];
            ll new_c = c + dx[i];
            if(new_r > 0 && new_r <= n && new_c > 0 && new_c <= m && graph[new_r][new_c] == 'O' && answer[new_r][new_c] == 'X')
            {
                answer[new_r][new_c] = 'O';
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