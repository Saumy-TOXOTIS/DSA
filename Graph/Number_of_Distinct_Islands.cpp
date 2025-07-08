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
#define Fast_IO ios_base::sync_with_stdio(false);cin.tie(0);//fast input and output

//Count the number of distinct island i.e. island with different shape

const ll N = 1005;
ll n, m;
ll graph[N + 1][N + 1];
ll visited[N + 1][N + 1];
ll dx[] = {-1,1,0,0};
ll dy[] = {0,0,-1,1};

/*########### Extra Functions ###########*/

void DFS(ll row,ll col,ll base_row,ll base_col,v(p(ll,ll))& shape)
{
    visited[row][col] = 1;
    shape.push_back({row - base_row,col - base_col});
    for(ll i = 0;i < 4;i++)
    {
        ll next_row = row + dy[i];
        ll next_col = col + dx[i];
        if(next_row > 0 && next_col > 0 && next_row <= n && next_col <= m && graph[next_row][next_col] && !visited[next_row][next_col])
        {
            DFS(next_row,next_col,base_row,base_col,shape);
        }
    }
}

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    cin>>n>>m;
    f1(i,1,n + 1,1)
    {
        f1(j,1,m + 1,1)
        {
            cin>>graph[i][j];
            visited[i][j] = 0;
        }
    }
    //0 - water and 1 - island
    set<v(p(ll,ll))> myset;
    f1(k,1,n + 1,1)
    {
        f1(j,1,m + 1,1)
        {
            if(!visited[k][j] && graph[k][j])
            {
                v(p(ll,ll)) shape;
                DFS(k,j,k,j,shape);
                //will also store the shape of discorvered island in 'shape' vector
                myset.insert(shape);
                //stores the unique shape only
            }
        }
    }
    cout<<myset.size()<<endl;
}