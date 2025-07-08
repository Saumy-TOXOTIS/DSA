// 111111  1111  11    11  1111  111111 1111  111111  
//   11   11  11  11  11  11  11   11    11   11      
//   11  11    11   11   11    11  11    11   111111  
//   11   11  11  11  11  11  11   11    11       11  
//   11    1111  11    11  1111    11   1111  111111  

/*##### Submission By - Saumy Tiwari #####*/

/*################ Macros ################*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll I, i, j, k, l, a, b, c, x, y;
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
/*########### Extra Functions ###########*/

bool is_safe(ll** arr, ll x, ll y, ll n)
{
    for(ll row = 0;row < x;row++)
    {
        if(arr[row][y] == 1)
        {
            return false;
        }
    }
    ll row = x, col = y;
    while(row >= 0 && col >= 0)
    {
        if(arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }
    row = x, col = y;
    while(row >= 0 && col <= n - 1)
    {
        if(arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }
    return true;
}

bool n_queen(ll** arr,ll x, ll n)
{
    if(x >= n)
    {
        return true;
    }

    for(ll col = 0;col < n;col++)
    {
        if(is_safe(arr,x,col,n))
        {
            arr[x][col] = 1;

            if(n_queen(arr,x+1,n))
            {
                return true;
            }

            //backtrack
            arr[x][col] = 0;
        }
    }

    return false;
}

/*################ Code #################*/

int main()
{
    d_ll(n)
    ll** solarr = new ll*[n];
    f1(i,n,1)
    {
        solarr[i] = new ll[n];
        f1(j,n,1)
        {
            solarr[i][j] = 0;
        }
    }
    //dynamically creating a matrix and initiallising it to zero
    if(n_queen(solarr,0,n))
    {
        cout<<endl;
        f1(i,n,1)
        {
            f1(j,n,1)
            {
                cout<<solarr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"No Placement exists!"<<endl;
    }
}