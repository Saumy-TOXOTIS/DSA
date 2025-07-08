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
#define psb push_back
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
#define Fast_IO ios_base::sync_with_stdio(0);cin.tie(0);//fast input and output
ll expo(ll a,ll b,ll mod){ll res=1; while(b>0){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b=b>>1;}return res;}
ll mminvprime(ll a,ll b){return expo(a,b-2,b);}
ll mod_add(ll a,ll b,ll m){a=a%m;b=b%m;return(((a+b)%m)+m)%m;}
ll mod_mul(ll a,ll b,ll m){a=a%m;b=b%m;return(((a*b)%m)+m)%m;}
ll mod_sub(ll a,ll b,ll m){a=a%m;b=b%m;return((a-b+m)%m);}
ll mod_div(ll a,ll b,ll m){a=a%m;b=b%m;return(mod_mul(a,mminvprime(b,m),m)+m)%m;}

//Strongly connected components are valid to directed graphs
//Step 1 : Sort all the edges according to finishing time
//Step 2 : Reverse all the edges
//Step 3 : Do a DFS

const ll N = 2e5 + 5;
v(ll) graph[N];
v(ll) reversed_graph[N];
ll n, m;
ll visited[N];
stack<ll> finished;

/*########### Extra Functions ###########*/

void DFS(ll node)
{
    visited[node] = 1;
    for(auto item : graph[node])
    {
        if(!visited[item])
        {
            DFS(item);
        }
    }
    finished.push(node);//store the nodes according to their finishing time
}

void DFS_1(ll node)
{
    visited[node] = 1;
    for(auto item : reversed_graph[node])
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
    Fast_IO
    //use before taking any input
    memset(visited,0,sizeof(visited));
    cin>>n>>m;
    f1(i,0,m,1)
    {
        d_ll(a) d_ll(b)//an edge between vertices a and b and directed as a->b
        graph[a].psb(b);
    }
    //Step 1 :
    f1(i,1,n + 1,1)
    {
        if(!visited[i])
        {
            DFS(i);
        }
    }
    //Step 2 :
    f1(i,1,n + 1,1)
    {
        visited[i] = 0;
        for(auto item : graph[i])
        {
            reversed_graph[item].psb(i);//reversing the edge direction
        }
    }
    //Step 3 :
    ll SCC = 0;
    while(!finished.empty())
    {
        ll node = finished.top();
        finished.pop();
        if(!visited[node])
        {
            SCC++;
            DFS_1(node);
        }
    }
    cout<<SCC<<endl;
}