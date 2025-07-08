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

//Given array you have to reach from first position to last position and in a moment you can either jump 1 or 2 step ahead cost of jumping from ith to jth index is absolute value of difference between those elements. Minimise the Cose of reaching the end

/*########### Extra Functions ###########*/

ll min_cost(vll& array,ll index,vll& dp)
{
    if(index == 0)
    {
        return 0;
    }
    if(index == 1)
    {
        return abs(array[0] - array[1]);
    }
    if(dp[index] != -1)
    {
        return dp[index];
    }
    //if we already know for index then no need to calculate
    ll one_step = min_cost(array,index - 1,dp) + abs(array[index] - array[index - 1]);
    ll two_step = min_cost(array,index - 2,dp) + abs(array[index] - array[index - 2]);
    //trying all possible ways
    return (dp[index] = min(one_step,two_step));
    //if calculated then need for memoisation
    //since asked about minimum so finding minimum
}

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    d_ll(n)
    d_llVecArr(a,n)
    vll dp(max(0ll,n + 1),-1);//answer from memoisation
    cout<<min_cost(a,n - 1,dp)<<endl;
    vll dummy_dp(max(0ll,n + 1), - 1);
    dp[0] = 0;
    ll one_step, two_step;
    f1(i,1,n,1)
    {
        one_step = dp[i - 1] + abs(a[i] - a[i - 1]);
        if(i > 1)
        {
            two_step = dp[i - 2] + abs(a[i] - a[i - 2]);
        }
        dp[i] = min(one_step,two_step);
    }//answer from tabulation
    cout<<dp[n - 1]<<endl;
}