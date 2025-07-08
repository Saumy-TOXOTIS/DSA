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

//Ninja has a grid of size (R x C) and each cell of the grid contains some chocolates and he has two friends Alice and Bob. Initially Alice is at top left position and Bob is on the top right corner in the gird. Each of them can move from current cell to cell below them  by goind down or down_left or down_right and have to pick up the chocolated on the grid they are standing and number of chocolates in that cell becomes 0. Return the maximum number of chocolates ninja can collect with help of his friends

/*########### Extra Functions ###########*/

ll max_chocolates(v(v(ll))& grid,ll i,ll aj,ll bj,ll n,ll m,v(v(v(ll)))& dp)
{
    //Step 1 : Express everything in terms of alice's (ai,aj) bob's (bi,bj) {Since its problem of 3D dp} and define base cases
    //Since at the same time alice and bob both would be at the same row this implies that ai == aj this implies that ai = aj = i
    if((aj < 0 || aj >= m) || (bj < 0 || bj >= m))
    {
        return lMIN;
    }
    if(i == n - 1)
    {
        if(aj == bj)
        {
            return grid[i][aj];
        }
        else
        {
            return grid[i][aj] + grid[i][bj];
        }
    }
    if(dp[i][aj][bj] != -1)
    {
        return dp[i][aj][bj];
    }
    //Step 2 : Do all the possible stuffs
    ll maxi = lMIN;
    for(ll a = -1;a <= 1;a++)
    {
        for(ll b = -1;b <= 1;b++)
        {
            ll movement;
            if(aj == bj)
            {
                movement = grid[i][aj];
            }
            else
            {
                movement = grid[i][aj] + grid[i][bj];
            }
            movement += max_chocolates(grid,i + 1,aj + a,bj + b,n,m,dp);
            maxi = max(maxi,movement);
        }
    }
    //Step 3 : As said figure out the maximum number of chocolates
    return (dp[i][aj][bj] = maxi);
}

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    d_ll(R) d_ll(C)
    v(v(ll)) grid(R,v(ll)(C));
    f1(i,0,R,1)
    {
        f1(j,0,C,1)
        {
            cin>>grid[i][j];
        }
    }
    v(v(v(ll))) dp(R,v(v(ll))(C,v(ll)(C,-1)));
    cout<<max_chocolates(grid,0,0,C - 1,R,C,dp)<<endl;//answer from memoisation
    v(v(v(ll))) dummy(R,v(v(ll))(C,v(ll)(C,-1)));
}