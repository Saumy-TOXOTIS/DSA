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

//Depth wise traversal

const ll N = 1005;
ll n;
v(ll) graph[N + 1];
ll visited[N + 1];

/*########### Extra Functions ###########*/

bool DFS(ll node,ll parent)
{
    visited[node] = 1;
    for(auto item : graph[node])
    {
        if(!visited[item])
        {
            if(DFS(item,node))
            {
                return true;
            }
        }
        else
        {
            if(item != parent)
            {
                return true;
            }
        }
    }
    return false;
}

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
    graph[8].push_back(2);graph[8].push_back(9);
    graph[9].push_back(10);
    graph[10].push_back(8);
    bool cycle = false;
    f1(i,1,n + 1,1)
    {
        if(DFS(i,i))
        {
            cycle = true;
            break;
        }
    }
    if(cycle)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}