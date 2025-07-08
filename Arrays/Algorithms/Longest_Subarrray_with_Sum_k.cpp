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

/*########### Extra Functions ###########*/

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    d_ll(n) d_ll(k)
    d_llArr(a,n)
    //better solution for arrays consisting positive, negative and zero integers
    ll sum = 0, max_length = 0;
    map<ll,ll> mapping;
    f1(i,0,n,1)
    {
        sum += a[i];
        if(sum == k)
        {
            max_length = max(max_length,i + 1);
        }
        ll remaining = sum - k;
        if(mapping.find(remaining) != mapping.end())
        {
            ll current_length = i - mapping[remaining];
            max_length = max(max_length,current_length);
        }
        if(mapping.find(sum) == mapping.end())
        {
            mapping[sum] = i;
        }
    }
    cout<<max_length<<endl;
    //better solution for arrays consisting for positive and zero integers only
    // ll first = 0, last = 0;
    // ll sum = a[0], max_length = 0;
    // while(last < n)
    // {
    //     while(left <= right && sum > k)
    //     {
    //         sum -= a[first];
    //         first++;
    //     }
    //     if(sum == k)
    //     {
    //         max_length = max(max_length,last - first + 1);
    //     }
    //     last++;
    //     if(last < n)
    //     {
    //         sum += a[last];
    //     }
    // }
    // cout<<max_length<<endl;
}