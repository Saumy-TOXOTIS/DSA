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
#define d_llMat(a,row,column) ll a[row][column];f1(i,0,row,1){f1(i,0,column,1){cin>>a[i][j];}}
#define d_llVecArr(a,n) vll a;f1(i,0,n,1){ll VAR;cin>>VAR;a.push_back(VAR);}
#define d_floatArr(a,n) float a[n];f1(i,0,n,1){cin>>a[i];}
#define d_doubleArr(a,n) double a[n];f1(i,0,n,1){cin>>a[i];}
#define Fast_IO ios_base::sync_with_stdio(false);cin.tie(0);//fast input and output

//Given array you have to reach from first position to last position and in a moment you can jump at most k and cost of jumping from ith to jth index is absolute value of difference between those elements. Minimise the Cose of reaching the end

/*########### Extra Functions ###########*/

ll min_cost(vll& array,ll jumps,ll index,ll cost,vll& dp)
{
    if(index == 0)
    {
        return 0;
    }
    if(dp[index] != -1)
    {
        return dp[index];
    }
    for(ll j = 1;j <= jumps;j++)
    {
        if(index - j >= 0)
        {
            cost = min(cost,min_cost(array,jumps,index - j,cost,dp) + abs(array[index] - array[index - j]));
        }
    }
    return (dp[index] = cost);
}

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    d_ll(n) d_ll(k)
    d_llVecArr(a,n)
    vll dp(max(0ll,n + 1), -1);//answer from memoisation
    cout<<min_cost(a,k,n - 1,lMAX,dp)<<endl;
    vll dummy_dp(n + 1,lMAX);
    dp[0] = 0;//base case
    f1(i,1,n,1)
    {
        f1(j,1,k + 1,1)
        {
            if(i - j >= 0)
            {
                dp[i] = min(dp[i],dp[i - j] + abs(a[i] - a[i - j]));
            }
        }
    }
    cout<<dp[n - 1]<<endl;//answer from tabulation
}