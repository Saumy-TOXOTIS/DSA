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
#define vll vector<ll>
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define MOD 1000000007ll
#define f1(I,a,t,b) for((I) = (a);(I) < (t);(I)+=(b))
#define f2(I,a,t,b) for((I) = (a);(I) >= (t);(I)-=(b))
#define d_ll(n) ll n;cin>>n;
#define d_string(s) string s;cin>>s;
#define d_float(n) float n;cin>>n;
#define d_double(n) double n;cin>>n;
#define d_llArr(a,n) ll a[n];f1(i,0,n,1){cin>>a[i];}
#define d_llMat(a,row,column) ll a[row][column];f1(i,0,row,1){f1(j,0,column,1){cin>>a[i][j];}}
#define d_llVecArr(a,n) vll a;f1(i,0,n,1){ll VAR;cin>>VAR;a.push_back(VAR);}
#define d_floatArr(a,n) float a[n];f1(i,0,n,1){cin>>a[i];}
#define d_doubleArr(a,n) double a[n];f1(i,0,n,1){cin>>a[i];}
#define Fast_IO ios_base::sync_with_stdio(false);cin.tie(0);//fast input and output

//Have to reach from (0,0) -> (n - 1,m - 1) and return minimum path sum

/*########### Extra Functions ###########*/

ll min_path_sum(vector<vll>& grid,ll i,ll j,vector<vll>& dp)
{
    //Step 1 : Expressed everything in terms of (i,j) and defined base cases
    if(i == 0 && j == 0)
    {
        return grid[i][j];
    }
    if(i < 0 || j < 0)
    {
        return 1000000000ll;
    }
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    //Step 2 : Do all the possible stuffs
    return (dp[i][j] = min(grid[i][j] + min_path_sum(grid,i - 1,j,dp),grid[i][j] + min_path_sum(grid,i,j - 1,dp)));
    //Step 3 : As said figured out the minimum path sum
}

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    d_ll(n) d_ll(m)
    vector<vll> grid(n,vll(m));
    f1(i,0,n,1)
    {
        f1(j,0,m,1)
        {
            cin>>grid[i][j];
        }
    }
    vector<vll> dp(n,vll(m,-1));
    cout<<min_path_sum(grid,n - 1,m - 1,dp)<<endl;//answer from memoisation
    vector<vll> dummy(n,vll(m));
    dummy[0][0] = grid[0][0];
    //base case
    f1(i,0,n,1)
    {
        f1(j,0,m,1)
        {
            if(i == 0 && j == 0)
            {
                continue;
            }
            else
            {
                ll up = lMAX;
                ll left = lMAX;
                if(i > 0)
                {
                    up = grid[i][j] + dummy[i - 1][j];
                }
                if(j > 0)
                {
                    left = grid[i][j] + dummy[i][j - 1];
                }
                dummy[i][j] = min(up,left);
            }
        }
    }
    cout<<dummy[n - 1][m - 1]<<endl;//answer from tabulation
}