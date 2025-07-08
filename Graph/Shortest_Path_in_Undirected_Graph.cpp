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

//Finding Shortest path from starting node to all other nodes in a Undirected Graph
//edges having unit weights
//Since unit weight, we can apply 'plain BFS algorithm'

const ll N = 2e5 + 5;
ll n, source;
v(ll) graph[N];
ll visited[N] = {0};
ll path[N] = {0};
//this path array eventually marks every point as 1 if it comes in a particular path, basically used here for path detetction
queue<p(ll,ll)> ordering;
//stores ordering
ll dist[N];

/*########### Extra Functions ###########*/

void BFS()
{
    while(!ordering.empty())
    {
        p(ll,ll) node = ordering.front();
        ordering.pop();
        for(auto item : graph[node.F])
        {
            if(node.S + 1 < dist[item])
            {
                dist[item] = node.S + 1;
                ordering.push({item,dist[item]});
            }
        }
    }
}

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    cin>>n>>source;
    graph[0].psb(1);graph[0].psb(3);
    graph[1].psb(0);graph[1].psb(2);graph[1].psb(3);
    graph[2].psb(1);graph[2].psb(6);
    graph[3].psb(0);graph[3].psb(4);
    graph[4].psb(3);graph[4].psb(5);
    graph[5].psb(4);graph[5].psb(6);
    graph[6].psb(2);graph[6].psb(5);graph[6].psb(7);graph[6].psb(8);
    graph[7].psb(6);graph[7].psb(8);
    graph[8].psb(6);graph[8].psb(7);
    f1(i,0,n + 1,1)
    {
        dist[i] = 1e9;
    }
    dist[source] = 0;
    ordering.push({source,0});
    BFS();
    f1(i,0,n + 1,1)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}