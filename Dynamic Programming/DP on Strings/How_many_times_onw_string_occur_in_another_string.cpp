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
#define __lcm(a,b) (a*b)/(__gcd(a,b))
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
#define Fast_IO ios_base::sync_with_stdio(0);cin.tie(0);//fast input and output
ll expo(ll a,ll b,ll mod){ll res=1; while(b>0){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b=b>>1;}return res;}
ll mminvprime(ll a,ll b){return expo(a,b-2,b);}
ll mod_add(ll a,ll b,ll m){a=a%m;b=b%m;return(((a+b)%m)+m)%m;}
ll mod_mul(ll a,ll b,ll m){a=a%m;b=b%m;return(((a*b)%m)+m)%m;}
ll mod_sub(ll a,ll b,ll m){a=a%m;b=b%m;return((a-b+m)%m);}
ll mod_div(ll a,ll b,ll m){a=a%m;b=b%m;return(mod_mul(a,mminvprime(b,m),m)+m)%m;}

//Return Number of times string s2 occurs in string s1

/*########### Extra Functions ###########*/

ll occurence(string s1,string s2,ll index_1,ll index_2,v(v(ll))& dp)
{
    //Step 1 : Expressed everything in terms of index and define base case
    if(index_2 < 0)
    {
        return 1;
    }
    if(index_1 < 0)
    {
        return 0;
    }
    if(dp[index_1][index_2] != -1)
    {
        return dp[index_1][index_2];
    }
    //Step 2 : Do all the possible stuffs
    if(s1[index_1] == s2[index_2])
    {
        dp[index_1][index_2] = occurence(s1,s2,index_1 - 1,index_2 - 1,dp) + occurence(s1,s2,index_1 - 1,index_2,dp);
    }
    else
    {
        dp[index_1][index_2] = occurence(s1,s2,index_1 - 1,index_2,dp);
    }
    //Step 3 : Figure out the number of occurences or basically count the ways
    return dp[index_1][index_2];
}

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    d_string(s1)
    d_string(s2)
    v(v(ll)) dp(s1.length(),v(ll) (s2.length(),-1));
    cout<<occurence(s1,s2,s1.length() - 1,s2.length() - 1,dp)<<endl;//answer from memoisation
    v(v(ll)) dummy(s1.length() + 1,v(ll) (s2.length() + 1,0));
    f1(i,0,s1.length() + 1,1)
    {
        dummy[i][0] = 1;
    }
    f1(i,0,s2.length() + 1,1)
    {
        dummy[0][i] = 0;
    }
    f1(i,1,s1.length() + 1,1)
    {
        f1(j,1,s2.length() + 1,1)
        {
            if(s1[i - 1] == s2[j - 1])
            {
                dummy[i][j] = dummy[i - 1][j - 1] + dummy[i - 1][j];
            }
            else
            {
                dummy[i][j] = dummy[i - 1][j];
            }
        }
    }
    cout<<dummy[s1.length()][s2.length()]<<endl;//answer from tabulation
}