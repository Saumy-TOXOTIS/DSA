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
Counting Sort :
Create a new array for counting how many there are of the different values.
Go through the array that needs to be sorted.
For each value, count it by increasing the counting array at the corresponding index.
After counting the values, go through the counting array to create the sorted array.
For each count in the counting array, create the correct number of elements, with values that correspond to the counting array index.
*/

int main()
{
    d_ll(n)
    d_llArray(a,n)
    ll Max = ll_MIN;
    f1(i,n,1)
    {
        if(a[i] >= Max)
        {
            Max = a[i];
        }
    }
    ll b[Max + 1] = {0};
    f1(i,n,1)
    {
        b[a[i]]++;
    }
    ll index = 0;
    f1(i,Max + 1,1)
    {
        f1(j,b[i],1)
        {
            a[j + index] = i;
        }
        index += b[i];
    }
    f1(i,n,1)
    {
        cout<<a[i]<<endl;
    }
}