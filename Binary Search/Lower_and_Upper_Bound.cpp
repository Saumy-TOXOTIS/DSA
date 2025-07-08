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

//Lower Bound : Return smallest Index of smallest number which is greater than or equal to given number.
//Upper Bound : Return smallest Index of smallest number which is greater than given number.
//Floor (of array) : Return largest number in array which is less than or qual to given number.
//Ceil (of array) : Return smallest number in array which is greater than or equal to given number. { Lower Bound }
//[NOTE] : Works well on sorted arrays and uses Binary Search method.

/*########### Extra Functions ###########*/

ll Rotated_Binary_Search(vll& array,ll n,ll target)
{
    ll low = 0;
    ll high = n - 1;
    ll mid;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(array[mid] == target)
        {
            return (mid + 1);
        }
        else
        {
            //Check if left part is Sorted
            if(array[low] <= array[mid])
            {
                //If element exists in left part then eliminate right part
                if(array[low] <= target && target <= array[mid])
                {
                    high = mid;
                }
                //If element is not in left part then eliminate left part itself
                else
                {
                    low = mid;
                }
            }
            //Check if Right part is Sorted
            else
            {
                //if element exists in right part then eliminate left part
                if(array[mid] <= target && target <= array[high])
                {
                    low = mid;
                }
                //If element is not in right part then eliminate right part itself
                else
                {
                    high = mid;
                }
            }
        }
    }
    return (array[mid] == target) ? (mid + 1) : -1;
}

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    d_ll(n) d_ll(k)
    d_llVecArr(a,n)//Rotated Sorted Array with unique elements
    ll ans = Rotated_Binary_Search(a,n,k);
    cout<<ans<<endl;
}