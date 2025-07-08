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
Selectioon Sort :
Much more efficient than Bubble Sort
Runs loop 1 less than array size.
In every loop takes the minimum element to first position.
And with completion of every loop searching size whithin array decreases by 1
Can be done either by shifting values one by one like in bubble sort or by swapping minimum found value in each iteration with first element
*/

int main()
{
    d_ll(n)
    d_llArray(a,n)

    //Byshifting values

    ll dummy = 0;
    bool swapped = false;
    f1(i,n - 1,1)
    {
        for(ll j = n - 1;j > i;j--)
        {
            if(a[j] < a[j - 1])
            {
                dummy = a[j];
                a[j] = a[j - 1];
                a[j - 1] = dummy;
                swapped = true;
            }
        }
        if(!swapped)
        {
            break;
        }//this ensures if sorted then no swap occur then no need to run further loops
    }

    //By swapping values

    ll dummy = 0;
    ll minimum = LLONG_MAX;
    ll index = 0;
    f1(i,n - 1,1)
    {
        minimum = LLONG_MAX;
        f2(j,i,n,1)
        {
            if(a[j] < minimum)
            {
                minimum = a[j];
                index = j;
            }
        }
        dummy = a[i];
        a[i] = minimum;
        a[index] = dummy;
    }

    f1(i,n,1)
    {
        cout<<a[i]<<endl;
    }
}