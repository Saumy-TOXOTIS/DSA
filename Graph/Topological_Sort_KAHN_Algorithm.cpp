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
#define Fast_IO ios_base::sync_with_stdio(0);cin.tie(0);//fast input and output
ll expo(ll a,ll b,ll mod){ll res=1; while(b>0){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b=b>>1;}return res;}
ll mminvprime(ll a,ll b){return expo(a,b-2,b);}
ll mod_add(ll a,ll b,ll m){a=a%m;b=b%m;return(((a+b)%m)+m)%m;}
ll mod_mul(ll a,ll b,ll m){a=a%m;b=b%m;return(((a*b)%m)+m)%m;}
ll mod_sub(ll a,ll b,ll m){a=a%m;b=b%m;return((a-b+m)%m);}
ll mod_div(ll a,ll b,ll m){a=a%m;b=b%m;return(mod_mul(a,mminvprime(b,m),m)+m)%m;}

//Linear ordereing of vertices such that if there is an edge between u and v, u appears before v in that ordering
//given a directed acyclic graph ( DAG )

const ll N = 2e5 + 5;
ll n;
v(ll) graph[N];
ll visited[N] = {0};
ll path[N] = {0};
ll indegree[N] = {0};
//this path array eventually marks every point as 1 if it comes in a particular path, basically used here for path detetction
queue<ll> ordering;
v(ll) ans;
//stores ordering

/*########### Extra Functions ###########*/

void BFS()
{
    while(!ordering.empty())
    {
        ll node = ordering.front();
        ordering.pop();
        ans.push_back(node);
        for(auto item : graph[node])
        {
            indegree[item]--;
            if(!indegree[item])
            {
                ordering.push(item);
            }
        }
    }
}
//using BFS

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    cin>>n;
    graph[1].push_back(2);
    graph[2].push_back(3);
    graph[3].push_back(4);graph[3].push_back(7);
    graph[4].push_back(5);
    graph[5].push_back(6);
    graph[7].push_back(5);
    graph[8].push_back(2);
    f1(i,1,n + 1,1)
    {
        for(auto item : graph[i])
        {
            indegree[item]++;
        }
    }
    f1(i,1,n + 1,1)
    {
        if(!indegree[i])
        {
            ordering.push(i);
        }
    }
    BFS();
    for(auto item : ans)
    {
        cout<<item<<" ";
    }
    cout<<endl;
}