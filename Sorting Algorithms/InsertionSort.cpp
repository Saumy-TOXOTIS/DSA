#include <bits/stdc++.h>
// #include "MyLib.h"
using namespace std;
using ll = long long;
ll I, i, j, t, k, l, a, b, c, x, y;
#define ll_MAX LLONG_MAX
#define ll_MIN LLONG_MIN
#define f1(I,t,b) for((I) = (0);(I) < (t);(I)+=(b))
#define f2(I,a,t,b) for((I) = (a);(I) < (t);(I)+=(b))
#define d_ll(n) ll n;cin>>n;
#define d_string(s) string s;cin>>s;
#define d_float(n) float n;cin>>n;
#define d_double(n) double n;cin>>n;
#define d_llArray(a,n) ll a[n];f1(i,n,1){cin>>a[i];}
#define d_floatArray(a,n) float a[n];f1(i,n,1){cin>>a[i];}
#define d_doubleArray(a,n) double a[n];f1(i,n,1){cin>>a[i];}

/*
Insertion Sort :
Btter than Bubble Sort
Take the first value from the unsorted part of the array.
Move the value into the correct place in the sorted part of the array.
Go through the unsorted part of the array again as many times as there are values.
*/

int main()
{
    d_ll(n)
    d_llArray(a,n)
    ll dummy = 0;
    f2(i,1,n,1)
    {
        if(a[i] < a[i - 1])
        {
            for(ll j = i - 1;j >= 0;j--)
            {
                if(a[j] > a[j + 1])
                {
                    dummy = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = dummy;
                } else {
                    break;
                }
            }
        }
    }
    f1(i,n,1)
    {
        cout<<a[i]<<endl;
    }
}