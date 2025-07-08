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

//Return total number of unique paths from top left cell of a matrix n x m to bottom right cell of matrix n x m { without any obstacle }
//Only right and down movements are allowed

//Tips :
//1. Express everything in terms of (i,j) {i - row number and j - column number}
//2. Do all possible stuffs allowed
//3. Sum all ways (if asked) / figure out max and min (if asked)

/*########### Extra Functions ###########*/

ll count_paths(ll i,ll j,vector<vll>& dp)
{
    //Step 1 : expressed in terms of (i,j) and write base cases
    if(i == 0 && j == 0)
    {
        return 1;
    }
    if(i < 0 || j < 0)
    {
        return 0;
    }
    //Step 2 : Do all possible stuffs
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    //Step 3 : As said count the number of ways
    return (dp[i][j] = (count_paths(i - 1,j,dp) + count_paths(i,j - 1,dp)));
}

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    d_ll(n) d_ll(m)
    //Count all possible ways from (0,0) -> (n - 1,m - 1)
    vector<vll> dp(n,vll (m,-1));
    cout<<count_paths(n - 1,m - 1,dp)%MOD<<endl;//answer from memoisation
    vector<vll> dummy(n,vll (m,0));
    dummy[0][0] = 1;
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
                ll up = 0, left = 0;
                if(i > 0)
                {
                    up = dp[i - 1][j];
                }
                if(j > 0)
                {
                    left = dp[i][j - 1];
                }
                dummy[i][j] = up + left;
            }
        }
    }
    cout<<dummy[n - 1][m - 1]%MOD<<endl;//answer from tabulation
}