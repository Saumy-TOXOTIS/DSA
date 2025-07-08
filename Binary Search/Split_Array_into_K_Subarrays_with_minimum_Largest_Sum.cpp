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

//Split array into K contigous subarrays such that largest sum of elements of all subarrays should be minimum
//Return the largest sum

/*########### Extra Functions ###########*/

ll Count_Subarrays(vll& array,ll max_sum)
{
    ll current_sum = 0;
    ll ans = 1;
    f1(i,0,array.size(),1)
    {
        current_sum += array[i];
        if(current_sum > max_sum)
        {
            current_sum = array[i];
            ans++;
        }
    }
    return ans;
}

ll Min_Largest_Sum_K_Split_Array(vll& array,ll n,ll k)
{
    ll low = *max_element(all(array));//gives maximum element in range
    ll high = accumulate(all(array),0);//gives sum of range
    ll mid;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(Count_Subarrays(array,mid) > k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    d_ll(n) d_ll(k)
    d_llVecArr(a,n)
    if(n >= k)
    {
        cout<<Min_Largest_Sum_K_Split_Array(a,n,k)<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
}