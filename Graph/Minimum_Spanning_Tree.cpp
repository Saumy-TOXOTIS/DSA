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
ll expo(ll a,ll b,ll mod){ll res=1;while(b>0){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b=b>>1;}return res;}
ll mminvprime(ll a,ll b){return expo(a,b-2,b);}
ll mod_add(ll a,ll b,ll m){a=a%m;b=b%m;return(((a+b)%m)+m)%m;}
ll mod_mul(ll a,ll b,ll m){a=a%m;b=b%m;return(((a*b)%m)+m)%m;}
ll mod_sub(ll a,ll b,ll m){a=a%m;b=b%m;return((a-b+m)%m);}
ll mod_div(ll a,ll b,ll m){a=a%m;b=b%m;return(mod_mul(a,mminvprime(b,m),m)+m)%m;}

//Undirected weighted graph
//Spanning tree - tree having N nodes and (N - 1) edges and all nodes are reachable from each other
//MST (Minimum Spanning Tree) - Spanning tree having least sum of all edge weights
//Graph can have more than one spanning tree
//Prim's Algorithm - Helps for finding minimum spanning tree

const ll N = 2e5 + 5;
ll n;
vector<pair<ll,ll>> graph[N];//graph[i] = {j,wt}, means i and j has edge between them with weight wt
ll visited[N] = {0};
vector<pair<ll,ll>> MST;
priority_queue<pair<pair<ll,ll>,ll>, vector<pair<pair<ll,ll>,ll>>, greater<pair<pair<ll,ll>,ll>>> pq;//{weight , node , parent}
ll sum_edge_weight = 0;

/*########### Extra Functions ###########*/

void Prims_Algorithm()
{
    while(!pq.empty())
    {
        pair<pair<ll,ll>,ll> data = pq.top();
        ll wt = data.F.F;
        ll node = data.F.S;
        ll parent = data.S;
        pq.pop();
        if(visited[node])
        {
            continue;
        }
        if(parent != -1 && !visited[node])
        {
            sum_edge_weight += wt;
            MST.psb({parent,node});
        }
        visited[node] = 1;
        for(auto item : graph[node])
        {
            if(!visited[item.F])
            {
                pq.push({{item.S,item.F},node});
            }
        }
    }
}

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    cin>>n;
    pq.push({{0,0},-1});
    Prims_Algorithm();
    //now you can print MST
}