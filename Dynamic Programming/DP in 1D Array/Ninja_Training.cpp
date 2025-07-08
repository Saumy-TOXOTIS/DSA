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

//Ninja is planning N days long training schedule, each day he can perform any one of three activities having merit points on each day. Ninja has to improve his skills so he can't do same activity on consecutive days. Find maximum merit points Ninja can have after N days.
//Input :
//2-D array of n X 3 {n - number of days} and {3 - merit points of three activities on each day}

/*########### Extra Functions ###########*/

ll max_merit(vector<vll>& m,ll index,ll last,vector<vll>& dp)
{
    if(index == 0)
    {
        multiset<ll,greater<ll>> tasks = {m[index][0],m[index][1],m[index][2]};
        if(last < 3)
        {
            tasks.erase(tasks.find(m[index][last]));
        }
        return *(tasks.begin());
    }
    //base condition
    if(dp[index][last] != -1)
    {
        return dp[index][last];
    }
    ll maxi = 0;
    //keeping maximum points that could be gained from a day {index} if it is known that {last} task had done in last day
    for(ll i = 0;i < 3;i++)
    {
        if(i != last)
        {
            maxi = max(maxi,m[index][i] + max_merit(m,index - 1,i,dp));
        }
        //if last day task is not done then only do this day, unless do other task
    }
    return (dp[index][last] = maxi);
}

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    d_ll(n)
    vector<vll> a(n,vll (3,0));
    f1(i,0,n,1)
    {
        f1(j,0,3,1)
        {
            cin>>a[i][j];
        }
    }
    vector<vll> dp(n,vll (4,-1));
    cout<<max_merit(a,n - 1,3,dp)<<endl;//answer from memoisation
    vector<vll> dummy(n,vll (4,-1));
    dummy[0][0] = max(a[0][1],a[0][2]);
    dummy[0][1] = max(a[0][0],a[0][2]);
    dummy[0][2] = max(a[0][0],a[0][1]);
    dummy[0][3] = max(max(a[0][0],a[0][1]),a[0][2]);
    //base cases
    f1(i,1,n,1)
    {
        for(ll last = 0;last <= 3;last++)
        {
            f1(j,0,3,1)
            {
                if(j != last)
                {
                    dummy[i][last] = max(dummy[i][last],a[i][j] + dummy[i - 1][j]);
                }
            }
        }
    }
    cout<<dummy[n - 1][3]<<endl;//answer from tabulation
}