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

//Find how much maximum price amount the thief can stole from house

/*########### Extra Functions ###########*/

ll Knapsack(ll n,ll W,ll index,v(ll)& weight,v(ll)& price,v(v(ll))& dp)
{
    //Step 1 : Expressed everything in terms of index and defined base case
    if(index == 0)
    {
        if(weight[index] <= W)
        {
            return price[index];
        }
        else
        {
            return 0;
        }
    }
    if(dp[index][W] != -1)
    {
        return dp[index][W];
    }
    //Step 2 : Do all the possible stuffs
    ll not_take = Knapsack(n,W,index - 1,weight,price,dp);
    ll take = lMIN;
    if(weight[index] <= W)
    {
        take = price[index] + Knapsack(n,W - weight[index],index - 1,weight,price,dp);
    }
    //Step 3 : As said figure out the maximum
    return (dp[index][W] = max(take,not_take));
}

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    d_ll(n) d_ll(W)//n items and W is max weight he/she can carry
    d_llVecArr(w,n)//weight of items
    d_llVecArr(p,n)//price of items
    v(v(ll)) dp(n,v(ll) (W + 1,-1));
    cout<<Knapsack(n,W,n - 1,w,p,dp)<<endl;//answer from memoisation
    v(v(ll)) dummy(n,v(ll) (W + 1,0));
    f1(i,w[0],W + 1,1)
    {
        dummy[0][i] = p[0];
    }
    //base case
    f1(i,1,n,1)
    {
        f1(j,0,W + 1,1)
        {
            ll not_take = dummy[i - 1][j];
            ll take = lMIN;
            if(w[i] <= j)
            {
                take = p[i] + dummy[i - 1][j - w[i]];
            }
            dummy[i][j] = max(take,not_take);
        }
    }
    cout<<dummy[n - 1][W]<<endl;//answer from tabulation
}