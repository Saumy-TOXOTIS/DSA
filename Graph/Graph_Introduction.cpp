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

/*########### Extra Functions ###########*/

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    d_ll(n) d_ll(m) //n - nodes and m - edges
    //next m lines would be m edges
    //If undirected edges would be both ways {m[i]1 -> m[i]2} and {m[i]2 -> m[i]1} m[i]1 and m[i]2 is ith input
    //if directed then edges would be along the given input {if input is (m[i]1,m[i]2) then it would be m[i]1 -> m[i]2} and vice versa
    //We can store in two ways :
    //1. Matrix
    v(v(ll)) graph_1(n + 1,v(ll) ((m + 1),0));
    f1(i,0,m,1)
    {
        ll u, v;
        cin>>u>>v;
        //in storing a weighted graph we can set values as given weight instead 1 that we did here
        graph_1[u][v] = 1;
        graph_1[v][u] = 1;//in directed this line will not be required
        //Undirected
    }
    //Graph Representation in Matrix
    //2. List
    v(ll) graph_2[n + 1];
    f1(i,0,m,1)
    {
        ll u, v;
        cin>>u>>v;
        //in storing a weighted graph we can push_back pair of edge and its weight instead of just pushing only edge that we did here
        graph_2[u].push_back(v);
        graph_2[v].push_back(u);//in directed this line will not be required
        //Undirected
    }
    //Graph representation in List
}