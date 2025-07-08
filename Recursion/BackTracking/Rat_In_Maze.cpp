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

//Rat is at (0,0) and has to reach the destination at(n - 1,n - 1). And it can more either Up, Down, Left or Right. 0 means blocked path and 1 means allowed

/*########### Extra Functions ###########*/

void Rat_In_Maze(ll s_row,ll s_column,vector<vll>& maze,ll n,vector<string>& ans,string moves,vector<vll>& visited)
{
    if(s_row == n - 1 && s_column == n - 1)
    {
        ans.push_back(moves);
        return;
    }
    //DownWard
    if(s_row + 1 < n && !visited[s_row + 1][s_column] && maze[s_row + 1][s_column])
    {
        visited[s_row][s_column] = 1;
        Rat_In_Maze(s_row + 1,s_column,maze,n,ans,moves + 'D',visited);
        visited[s_row][s_column] = 0;
    }
    //LeftWard
    if(s_column - 1 < n && !visited[s_row][s_column - 1] && maze[s_row][s_column - 1])
    {
        visited[s_row][s_column] = 1;
        Rat_In_Maze(s_row,s_column - 1,maze,n,ans,moves + 'L',visited);
        visited[s_row][s_column] = 0;
    }
    //RightWard
    if(s_column + 1 < n && !visited[s_row][s_column + 1] && maze[s_row][s_column + 1])
    {
        visited[s_row][s_column] = 1;
        Rat_In_Maze(s_row,s_column + 1,maze,n,ans,moves + 'R',visited);
        visited[s_row][s_column] = 0;
    }
    //UpWard
    if(s_row - 1 < n && !visited[s_row - 1][s_column] && maze[s_row - 1][s_column])
    {
        visited[s_row][s_column] = 1;
        Rat_In_Maze(s_row - 1,s_column,maze,n,ans,moves + 'U',visited);
        visited[s_row][s_column] = 0;
    }
}

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    d_ll(n)
    vector<vll> maze(n,vll (n,0));
    f1(i,0,n,1)
    {
        f1(j,0,n,1)
        {
            d_ll(var)
            maze[i][j] = var;
        }
    }
    vector<string> ans;
    vector<vll> visited(n,vll (n,0));
    Rat_In_Maze(0,0,maze,n,ans,"",visited);
    for(auto element : ans)
    {
        cout<<element<<endl;
    }
}