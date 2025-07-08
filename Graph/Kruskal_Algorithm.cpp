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

//Kruskal's Algorithm - helps us in finding minimum spanning tree
//Step 1 : Sort all the edges according to weight
//Step 2 : Apply disjoint set union by size method
//now after applying disjoin set methods, it'll first add edges with minimum weight and after encountering any vertex pair which are earlier connected already it'll ignore that always, This will make sure every time we add unique edges with minimum weights

/*########### Extra Functions ###########*/

class disjoint_set
{
    v(ll) parent;
    v(ll) rank;
    v(ll) size;
    public:
    disjoint_set(ll n)
    {
        size.resize(n + 1);
        rank.resize(n + 1,0);
        parent.resize(n + 1);
        f1(i,0,n + 1,1)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    //constructor
    ll find_ultimate_parent(ll node)
    {
        if(node == parent[node])
        {
            return node;
        }
        return (parent[node] = find_ultimate_parent(parent[node]));
    }
    //find ultimate parent of given node
    void union_by_rank(ll first_vertex,ll second_vertex)
    {
        ll upfv = find_ultimate_parent(first_vertex);
        ll upsv = find_ultimate_parent(second_vertex);
        if(upfv == upsv)
        {
            return;
        }
        if(rank[upfv] < rank[upsv])
        {
            parent[upfv] = upsv;
        }
        elif(rank[upfv] > rank[upsv])
        {
            parent[upsv] = upfv;
        }
        elif(rank[upfv] == rank[upsv])
        {
            parent[upsv] = upfv;
            rank[upfv]++;
        }
    }
    void union_by_size(ll first_vertex,ll second_vertex)
    {
        ll upfv = find_ultimate_parent(first_vertex);
        ll upsv = find_ultimate_parent(second_vertex);
        if(upfv == upsv)
        {
            return;
        }
        if(size[upfv] < size[upsv])
        {
            parent[upfv] = upsv;
            size[upsv] += size[upfv];
        }
        elif(size[upfv] > size[upsv])
        {
            parent[upsv] = upfv;
            size[upfv] += size[upsv];
        }
        elif(size[upfv] == size[upsv])
        {
            parent[upsv] = upfv;
            size[upfv] += size[upsv];
        }
    }
};

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    d_ll(n)
    //assuming we have aready sorted our edges accoding to weight
    //n - number of edges
    disjoint_set ds(n + 1);
    ll MST_weight = 0;
    f1(i,0,n,1)
    {
        ll wt, u, v;
        cin>>wt>>u>>v;
        if(ds.find_ultimate_parent(u) != ds.find_ultimate_parent(v))
        {
            MST_weight += wt;
            ds.union_by_size(u,v);
        }
    }
    cout<<MST_weight<<endl;
}