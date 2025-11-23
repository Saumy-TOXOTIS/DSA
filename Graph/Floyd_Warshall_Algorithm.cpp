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

//Undirected graph with given edge weights

//Floyd Warshall Algorithm for finding shortest path from multiple source to multiple destinations
//This algorithm basically checks every permutation of all possible paths between two vertices thats why it has so much high time complexity of O(n^3)

//[NOTE] : Floyd Warshall Algorithm also works with non negative edge weights

const ll N = 2e3 + 5;
ll n, source;
ll graph[N][N];//graph[i][j] = w, means there is an edge between i and j with weight w, if there is no edge between i and j then graph[i][j] = 1e9 ( or a larger value ) and graph[i][i] = 0
bool negative_cycle = false;

/*########### Extra Functions ###########*/

void Floyd_Warshall_Algorithm()
{
    for(int k = 1;k <= n;k++)
    {
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
            }
        }
    }
    for(int i = 1;i <= n;i++)
    {
        if(graph[i][i] < 0)
        {
            negative_cycle = true;
            return;
        }
        //if reaching to i to i itself is negative instead of zero then it has definitely a negative cycle
    }
}

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    cin>>n;
    f1(i,1,n + 1,1)
    {
        f1(j,1,n + 1,1)
        {
            if(i == j)
            {
                graph[i][j] = 0;
            }
            else
            {
                graph[i][j] = 1e9;
            }
        }
    }
    Floyd_Warshall_Algorithm();
    //after this graph[i][j] will yeild shortest path between i and j
    if(negative_cycle)
    {
        cout<<"Contains negative cycle!"<<endl;
    }
}