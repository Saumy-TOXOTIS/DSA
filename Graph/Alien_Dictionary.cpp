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
ll I, i, j, l, a, b, c, x, y;
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

//Given n alien word sorted according to alien dictionary and you know these words contains first k letters or english alphabet, you need to find out the ordering of those k letters in alien dictionary

const ll N = 2e5 + 5;
ll n, k;
v(ll) graph[N];
ll visited[N] = {0};
ll path[N] = {0};
//this path array eventually marks every point as 1 if it comes in a particular path, basically used here for path detetction
stack<ll> ordering;
//stores ordering

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
    ordering.push(node);
}
//using DFS

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    n = 5;
    k = 4;
    string array[] = {"baa","abcd","abca","cab","cad"};
    map<char,ll> index;
    f1(i,0,k,1)
    {
        index['a' + i] = (i + 1);
    }
    f1(i,1,n,1)
    {
        ll id1 = 0;
        ll id2 = 0;
        while(array[i - 1][id1] == array[i][id2] && id1 < array[i - 1].length() && id2 < array[i].length())
        {
            id1++;
            id2++;
        }
        if(array[i - 1][id1] == array[i][id2])
        {
            continue;
        }
        else
        {
            id1 = index[array[i - 1][id1]];
            id2 = index[array[i][id2]];
            if(find(all(graph[id1]),id2) != graph[id1].end())
            {
                graph[id1].push_back(id2);
            }
        }
    }
    f1(i,1,k + 1,1)
    {
        if(!visited[i])
        {
            DFS(i);
        }
    }
    while(!ordering.empty())
    {
        ll dummy = ordering.top();
        ordering.pop();
        cout<<char('a' + dummy - 1)<<" ";
    }
    cout<<endl;
}