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

//Given (n x m) grid filled with integers. Return the maximum path sum that can be obtained from a path starting from any cell in first row and ending to any cell in last row.
//You can move either down, diagonally right or diagonally left.

/*########### Extra Functions ###########*/

ll max_path(vector<vll>& grid,ll i,ll j,ll column,vector<vll>& dp)
{
    //Step 1 : Expressed everything in terms of (i,j) and defined base cases
    if(j < 0 || j >= column)
    {
        return lMIN;
    }
    if(i == 0)
    {
        return grid[i][j];
    }
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    //Step 2 : Do all the possible stuffs
    ll up = grid[i][j] + max_path(grid,i - 1,j,column,dp);
    ll up_left = grid[i][j] + max_path(grid,i - 1,j - 1,column,dp);
    ll up_right = grid[i][j] + max_path(grid,i - 1,j + 1,column,dp);
    //Step 3 : As said figure out the maximum path
    return (dp[i][j] = max(up,max(up_left,up_right)));
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
    ll maximum_path = lMIN;
    f1(i,0,m,1)
    {
        maximum_path = max(maximum_path,max_path(grid,n - 1,i,m,dp));
    }
    cout<<maximum_path<<endl;//answer from memoisation
    vector<vll> dummy(n,vll(m,-1));
    f1(i,0,m,1)
    {
        dummy[0][i] = grid[0][i];
    }
    //base case
    f1(i,1,n,1)
    {
        f1(j,0,m,1)
        {
            ll down = grid[i][j] + dummy[i - 1][j];
            ll down_left = lMIN;
            ll down_right = lMIN;
            if(j > 0)
            {
                down_left = grid[i][j] + dummy[i - 1][j - 1];
            }
            if(j < m - 1)
            {
                down_right = grid[i][j] + dummy[i - 1][j + 1];
            }
            dummy[i][j] = max(down,max(down_left,down_right));
        }
    }
    ll max_path_sum = lMIN;
    f1(i,0,m,1)
    {
        max_path_sum = max(max_path_sum,dummy[n - 1][i]);
    }
    cout<<max_path_sum<<endl;//answer from tabulation
}