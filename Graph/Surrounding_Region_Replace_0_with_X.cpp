//  ████████╗_██████╗_██╗__██╗_██████╗_████████╗██╗███████╗
//  ╚══██╔══╝██╔═══██╗╚██╗██╔╝██╔═══██╗╚══██╔══╝██║██╔════╝
//  ___██║___██║___██║_╚███╔╝_██║___██║___██║___██║███████╗
//  ___██║___██║___██║_██╔██╗_██║___██║___██║___██║╚════██║
//  ___██║___╚██████╔╝██╔╝_██╗╚██████╔╝___██║___██║███████║
//  ___╚═╝____╚═════╝_╚═╝__╚═╝_╚═════╝____╚═╝___╚═╝╚══════╝
//  _______________________________________________________

/*##### Submission By - Saumy Tiwari #####*/

/*################ Macros ################*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll I, i, j, k, l, a, b, c, x, y;
#define TOXOTIS int main()
#define lMAX LLONG_MAX
#define lMIN LLONG_MIN
#define elif else if
#define v(T) vector<T>
#define p(T1,T2) pair<T1,T2>
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define __lcm(a,b) (a*b)/(__gcd(a,b))
#define MOD 1000000007ll
#define f1(I,a,t,b) for((I) = (a);(I) < (t);(I)+=(b))
#define f2(I,a,t,b) for((I) = (a);(I) >= (t);(I)-=(b))
#define d_ll(n) ll n;cin>>n;
#define d_string(s) string s;cin>>s;
#define d_float(n) float n;cin>>n;
#define d_double(n) double n;cin>>n;
#define d_llArr(a,n) ll a[n];f1(i,0,n,1){cin>>a[i];}
#define d_llMat(a,row,column) ll a[row][column];f1(i,0,row,1){f1(j,0,column,1){cin>>a[i][j];}}
#define d_llVecArr(a,n) v(ll) a;f1(i,0,n,1){ll VAR;cin>>VAR;a.push_back(VAR);}
#define d_floatArr(a,n) float a[n];f1(i,0,n,1){cin>>a[i];}
#define d_doubleArr(a,n) double a[n];f1(i,0,n,1){cin>>a[i];}
#define Fast_IO ios_base::sync_with_stdio(false);cin.tie(0);//fast input and output

//Replace all 'O' with 'X' that are surrounded by 'X'

const ll N = 1005;
ll n, m;
char graph[N + 1][N + 1];
ll visited[N + 1][N + 1];
ll dx[] = {-1,1,0,0};
ll dy[] = {0,0,-1,1};

/*########### Extra Functions ###########*/

void DFS(ll row,ll col)
{
    visited[row][col] = 1;
    for(ll j = 0;j < 4;j++)
    {
        ll nrow = row + dy[j];
        ll ncol = col + dx[j];
        if(nrow > 0 && ncol > 0 && nrow <= n && ncol <= m && (graph[nrow][ncol] == 'O') && !visited[nrow][ncol])
        {
            DFS(nrow,ncol);
        }
    }
}

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    cin>>n>>m;
    f1(i,1,n + 1,1)
    {
        f1(j,1,m + 1,1)
        {
            char var;
            cin>>var;
            graph[i][j] = var;
        }
    }
    f1(i,1,m + 1,1)
    {
        if(graph[1][i] == 'O' && !visited[i][j])
        {
            DFS(1,i);
        }
        if(graph[n][i] == 'O' && !visited[i][j])
        {
            DFS(n,i);
        }
    }
    f1(i,1,n + 1,1)
    {
        if(graph[i][1] == 'O' && !visited[i][j])
        {
            DFS(i,1);
        }
        if(graph[i][m] == 'O' && !visited[i][j])
        {
            DFS(i,m);
        }
    }
    cout<<endl;
    f1(i,1,n + 1,1)
    {
        f1(j,1,m + 1,1)
        {
            if(!visited[i][j])
            {
                cout<<"X ";
            }
            else
            {
                cout<<"O ";
            }
        }
        cout<<endl;
    }
}