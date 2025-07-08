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

//Return minimum number of coins required to get target amount

/*########### Extra Functions ###########*/

ll coins(v(ll)& array,ll index,ll target,v(v(ll))& dp)
{
    //Step 1 : Expressed everything in terms of index and define base case
    if(index == 0)
    {
        if(target % array[index] == 0)
        {
            return (target/array[index]);
        }
        else
        {
            return 1e9;
        }
    }
    if(dp[index][target] != -1)
    {
        return dp[index][target];
    }
    //Step 2 : Do all the possible stuffs
    ll not_take = 0 + coins(array,index - 1,target,dp);
    ll take = 1e9;
    if(array[index] <= target)
    {
        take = 1 + coins(array,index,target - array[index],dp);//since infinite supply no need to go to net index after taking the denomination
    }
    //Step 3 : As said figure out the minimum coins
    return (dp[index][target] = min(take,not_take));
}

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    d_ll(n) d_ll(m)//n denominations of coins and to make target money of amount m
    d_llVecArr(d,n)//d[i] is denominations of ith coin
    v(v(ll)) dp(n,v(ll) (m + 1,-1));
    cout<<coins(d,n - 1,m,dp)<<endl;//answer from memoisation
    v(v(ll)) dummy(n,v(ll) (m + 1,0));
    f1(i,0,m + 1,1)
    {
        if(i % d[0] == 0)
        {
            dummy[0][i] = i/d[0];
        }
        else
        {
            dummy[0][i] = 1e9;
        }
    }
    //base case
    f1(i,1,n,1)
    {
        f1(j,0,m + 1,1)
        {
            ll not_take = 0 + dummy[i - 1][j];
            ll take = 1e9;
            if(d[i] <= j)
            {
                take = 1 + dummy[i - 1][j - d[i]];
            }
            dummy[i][j] = min(take,not_take);
        }
    }
    cout<<dummy[n - 1][m]<<endl;//answer from tabulation
}