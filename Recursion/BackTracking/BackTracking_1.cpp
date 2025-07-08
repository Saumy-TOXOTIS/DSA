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

bool is_safe(ll** board, ll x, ll y, ll m, ll n)
{
    if(x < n && y < m && board[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool rat_in_maze(ll** board, ll x, ll y, ll m, ll n, ll** solarr)
{
    if(x == n - 1 && y == m - 1)
    {
        solarr[x][y] = 1;
        return true;
    }

    if(is_safe(board,x,y,m,n))
    {
        solarr[x][y] = 1;
        if(rat_in_maze(board,x+1,y,m,n,solarr))
        {
            return true;
        }
        if(rat_in_maze(board,x,y+1,m,n,solarr))
        {
            return true;
        }
        //backtrack
        solarr[x][y] = 0;
        return false;
    }
    return false;
}

/*################ Code #################*/

int main()
{
    d_ll(m) d_ll(n)
    ll** board = new ll*[m];
    f1(i,m,1)
    {
        board[i] = new ll[n];
    }
    //dynamically creating a matrix
    f1(i,m,1)
    {
        f1(j,n,1)
        {
            cin>>board[i][j];
        }
    }
    ll** solarr = new ll*[m];
    f1(i,m,1)
    {
        solarr[i] = new ll[n];
        f1(j,n,1)
        {
            solarr[i][j] = 0;
        }
    }
    //dynamically creating a matrix and initiallising it to zero
    if(rat_in_maze(board,0,0,m,n,solarr))
    {
        cout<<endl;
        f1(i,m,1)
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
        cout<<"No solution path exists, for given condition!"<<endl;
    }
}