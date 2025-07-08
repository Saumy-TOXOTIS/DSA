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

//Return maximum sum of subsequence in which none of element should be adjacent

/*########### Extra Functions ###########*/

ll max_sum(vll& array,ll index,vll& dp)
{
    if(index == 0)
    {
        return array[index];
    }
    if(index < 0)
    {
        return 0;
    }
    if(dp[index] != -1)
    {
        return dp[index];
    }
    //if earlier calculated result for specific index then no need for further calculation
    ll pick = array[index] + max_sum(array,index - 2,dp);
    //picking up an element to form subsequence
    ll not_pick = 0 + max_sum(array,index - 1,dp);
    //not picking up an element in our subsequence
    return (dp[index] = max(pick,not_pick));
    // memoising the result for specific index
}

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    d_ll(n)
    d_llVecArr(a,n)
    vll dp(n + 1, -1);
    cout<<max_sum(a,n - 1,dp)<<endl;//answer from memoisation
    vll dummy(n + 1,-1);
    dp[0] = a[0];//base case
    ll take, not_take;
    f1(i,1,n,1)
    {
        take = a[i];
        if(i > 1)
        {
            take += dp[i - 2];
        }
        not_take = 0 + dp[i - 1];
        dp[i] = max(take,not_take);
    }
    cout<<dp[n - 1]<<endl;//answer from tabulation
}