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
Quick Sort :
One of the fastest Sorting Algorithm
Choose a value in the array to be the pivot element.
Order the rest of the array so that lower values than the pivot element are on the left, and higher values are on the right.
Swap the pivot element with the first element of the higher values so that the pivot element lands in between the lower and higher values.
Do the same operations (recursively) for the sub-arrays on the left and right side of the pivot element.
*/

void swap(ll *a,ll *b)
{
    ll dummy = *a;
    *a = *b;
    *b = dummy;
}

ll section(ll a[],ll first,ll end)
{
    ll pivot = a[end];
    ll index = first - 1;
    f2(i,first,end,1)
    {
        if(a[i] <= pivot)
        {
            index += 1;
            swap(&a[i],&a[index]);
        }
    }
    swap(&a[end],&a[index + 1]);
    return (index + 1);
}

void quicksort(ll a[],ll first,ll end)
{
    //if first == end then only one element left and no need to sort
    if(first < end)
    {
        ll pivot_index = section(a,first,end);
        quicksort(a,first,pivot_index - 1);
        quicksort(a,pivot_index + 1,end);
    }
}

int main()
{
    d_ll(n)
    d_llArray(a,n)
    quicksort(a,0,n - 1);
    f1(i,n,1)
    {
        cout<<a[i]<<endl;
    }
}