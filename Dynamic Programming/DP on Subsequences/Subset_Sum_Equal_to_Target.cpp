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

//Check is there exists a subset whose sum is K

/*########### Extra Functions ###########*/

bool sum_k_exists(v(ll)& array,ll target,ll index,v(v(ll))& dp)
{
    //Step 1 : Expressed everything in terms of index and defined base cases
    if(target == 0)
    {
        return 1;
    }
    if(index == 0)
    {
        if(array[index] == target)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(dp[index][target] != -1)
    {
        return dp[index][target];
    }
    //Step 2 : Do all the possible stuffs
    //Picked the element where i was standing on
    if((array[index] <= target) && sum_k_exists(array,target - array[index],index - 1,dp))
    {
        return (dp[index][target] = 1);
    }
    //Not picked up the element where i was standing on
    if(sum_k_exists(array,target,index - 1,dp))
    {
        return (dp[index][target] = 1);
    }
    //Step 3 : Figure out whether sum exists or not
    return (dp[index][target] = 0);
}

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    d_ll(n) d_ll(k)
    d_llVecArr(a,n)
    v(v(ll)) dp(n,v(ll)(k + 1,-1));
    if(sum_k_exists(a,k,n - 1,dp))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }//answer from memoisation
}