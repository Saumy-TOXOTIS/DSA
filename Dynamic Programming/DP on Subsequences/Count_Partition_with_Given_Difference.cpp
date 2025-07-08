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

/*########### Extra Functions ###########*/

ll count_subsets_sum_k(v(ll)& array,ll index,ll target,v(v(ll))& dp)
{
    //Step 1 : Expressed everything in terms of index and defined base case
    if(index == 0)
    {
        if(target == 0 && array[index] == 0)
        {
            return 2;
        }
        if(array[index] == target || target == 0)
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
    ll not_pick = count_subsets_sum_k(array,index - 1,target,dp);
    //ignoring element
    ll pick = 0;
    if(array[index] <= target)
    {
        pick = count_subsets_sum_k(array,index - 1,target - array[index],dp);
    }
    //considering element
    //Step 3 : As said count the possible subsets with sum k
    return (dp[index][target] = (pick + not_pick));
}

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    d_ll(n) d_ll(d)
    d_llVecArr(a,n)

    //lets suppose one of subset have sum S1 and another one with S2 then S1 - S2 = d {S1 >= S2}
    //=> S1 + S2 = Sum
    //=> S1 = Sum - S2;
    //=> Sum - 2*S2 = d
    //=> S2 = (Sum - d)/2
    //i.e. we have to find number of subsets with sum equal to S2 calculated above;

    ll Sum = accumulate(all(a),0);
    Sum = Sum - d;
    if(Sum >= 0 && (Sum % 2 == 0))
    {
        Sum = Sum/2;
        v(v(ll)) dp(n,v(ll) (Sum + 1,-1));
        cout<<count_subsets_sum_k(a,n - 1,Sum,dp)<<endl;//answer from memoisation
        v(v(ll)) dummy(n,v(ll) (Sum + 1,0));
        f1(i,0,n,1)
        {
            dummy[i][0] = 1;
        }
        if(a[0] <= Sum)
        {
            if(a[0] == 0)
            {
                dummy[0][a[0]] = 2;
            }
            else
            {
                dummy[0][a[0]] = 1;
            }
        }
        //base case
        f1(i,1,n,1)
        {
            f1(j,0,Sum + 1,1)
            {
                ll not_pick = dummy[i - 1][j];
                ll pick = 0;
                if(a[i] <= j)
                {
                    pick = dummy[i - 1][j - a[i]];
                }
                dummy[i][j] = (pick + not_pick);
            }
        }
        cout<<dummy[n - 1][Sum]<<endl;//answer from tabulation
    }
    else
    {
        cout<<0<<endl;
    }
}