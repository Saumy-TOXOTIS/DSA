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

//Fixed Starting point to Variable Ending point
//Given Triangular Array like :
//*
//**
//***
//****
//*****
//...
//You are in first row and have to reach in the last row, and there could be a lot of paths. Return the minimum path sum

/*########### Extra Functions ###########*/

ll min_path(vector<vll>& triangle,ll i,ll j,ll n,vector<vll>& dp)
{
    //Step 1 : Expressed everything in terms of (i,j) and defined base cases
    if(i == n - 1)
    {
        return triangle[i][j];
    }
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    //Step 2 : Explore/Do all the possible stuffs
    return (dp[i][j] = min(triangle[i][j] + min_path(triangle,i + 1,j,n,dp),triangle[i][j] + min_path(triangle,i + 1,j + 1,n,dp)));
    //Step 3 : As said figure out the minimum path sum
}

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    d_ll(n)
    vector<vll> triangle;
    f1(i,0,n,1)
    {
        vll dummy;
        f1(j,0,i + 1,1)
        {
            d_ll(var)
            dummy.push_back(var);
        }
        triangle.push_back(dummy);
    }
    vector<vll> dp(n,vll (n,-1));
    cout<<min_path(triangle,0,0,n,dp)<<endl;//answer from memoisation
    vector<vll> dummy(n,vll (n,-1));
    f1(i,0,n,1)
    {
        dummy[n - 1][i] = triangle[n - 1][i];
    }
    for(ll i = n - 2;i >= 0;i--)
    {
        for(ll j = 0;j < (i + 1);j++)
        {
            dummy[i][j] = min(triangle[i][j] + dummy[i + 1][j],triangle[i][j] + dummy[i + 1][j + 1]);
        }
    }
    cout<<dummy[0][0]<<endl;//answer from tabulation
    //See tabulation goes opposite in reference to recursion. Recursion goes from (0,0) to last row and here tabulation goes from last row to (0,0)
}