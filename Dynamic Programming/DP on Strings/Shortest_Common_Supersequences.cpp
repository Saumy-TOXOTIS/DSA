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

//Return Supersequence of shortest length
//Supersequence of string s1 and string s2 would be that string, which should contain string s1 and string s2 and subsequence
//Length would be ofc [s1.length() + s2.length() - length(longest common subsequence)]

/*########### Extra Functions ###########*/

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    d_string(s1)
    d_string(s2)
    v(v(ll)) dp(s1.length() + 1,v(ll) (s2.length() + 1,0));
    f1(i,0,s2.length(),1)
    {
        dp[0][i] = 0;
    }
    f1(i,0,s1.length(),1)
    {
        dp[i][0] = 0;
    }
    //base case
    f1(i,1,s1.length() + 1,1)
    {
        f1(j,1,s2.length() + 1,1)
        {
            if(s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 0 + max(dp[i - 1][j],dp[i][j - 1]);
            }
        }
    }
    //Tabulation
    string ans = "";
    ll id1 = s1.length();
    ll id2 = s2.length();
    while(id1 > 0 && id2 > 0)
    {
        if(s1[id1 - 1] == s2[id2 - 1])
        {
            ans += s1[id1 - 1];
            id1--;
            id2--;
            //if charecters are equal then store it to answer
        }
        else
        {
            if(dp[id1 - 1][id2] > dp[id1][id2 - 1])
            {
                ans += s1[id1 - 1];//**
                id1--;
            }
            else
            {
                ans += s2[id2 - 1];//**
                id2--;
            }
            //if charecter not equal then go to that index from where maximum length ancestors came from
        }
    }
    while(id1 > 0)
    {
        ans += s1[id1 - 1];
        id1--;
    }//**
    while(id2 > 0)
    {
        ans += s2[id2 - 1];
        id2--;
    }//**
    reverse(all(ans));//since answer will be store from back to start, so we have to reverse it
    cout<<ans<<endl;
}