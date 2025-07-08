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

//Articulation Points - Any node in graph on whose removal graph breaks down into multiple parts is known as articulation points

const ll N = 2e5 + 5;
v(ll) graph[N];
ll n, m;
ll visited[N];
ll time_insertion[N] = {0};
ll lowest_time[N] = {0};
v(ll) articulation_points(N,0);
stack<ll> finished;
ll timer = 0;

/*########### Extra Functions ###########*/

void Articulation_Points(ll node,ll parent)
{
    visited[node] = 1;
    time_insertion[node] = lowest_time[node] = timer;
    timer++;
    ll child = 0;
    for(auto item : graph[node])
    {
        if(item == parent)
        {
            continue;
        }
        if(!visited[node])
        {
            Articulation_Points(item,node);
            lowest_time[node] = min(lowest_time[node],lowest_time[item]);
            if((lowest_time[item] >= time_insertion[node]) && (parent != -1))
            {
                articulation_points[node] = 1;
            }
            child++;
        }
        else
        {
            lowest_time[node] = min(lowest_time[node],time_insertion[item]);
        }
    }
    if((child > 1) && (parent == -1))
    {
        articulation_points[node] = 1;
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
        graph[b].psb(a);
    }
    Articulation_Points(0,-1);
}