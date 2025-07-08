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

//Place N queens on N x N chessboard with following rules :
//[Rules] : 1. Every Row should have exactly 1 queen
//          2. Every Column should have exactly 1 queen
//          3. No two Queens should attack each other
//Prints only one solution, if you want for all solution you can store results into a vector in base condtition
//We can reduce time complexity by maintaining hash maps for left upper diagonal, left wards and left lower diagonal

/*########### Extra Functions ###########*/

bool isPossible(ll row,ll column,vector<string>& board,ll n)
{
    //Check Upper Left Diagonal
    ll dummy_row = row;
    ll dummy_column = column;
    while(row >= 0 && column >= 0)
    {
        if(board[row][column] == 'Q')
        {
            return false;
        }
        row--;
        column--;
    }
    //Check Leftwards
    row = dummy_row;
    column = dummy_column;
    while(column >= 0)
    {
        if(board[row][column] == 'Q')
        {
            return false;
        }
        column--;
    }
    //Check Lower Left Diagonal
    row = dummy_row;
    column = dummy_column;
    while(row < n && column >= 0)
    {
        if(board[row][column] == 'Q')
        {
            return false;
        }
        row++;
        column--;
    }
    return true;
}

bool N_Queen(ll column,vector<string>& board,ll n)
{
    if(column == n)
    {
        for(auto element : board)
        {
            for(auto items : element)
            {
                cout<<items<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;;
    }
    for(ll row = 0;row < n;row++)
    {
        if(isPossible(row,column,board,n))
        {
            board[row][column] = 'Q';
            if(N_Queen(column + 1,board,n))
            {
                return true;
            }
            board[row][column] = '.';
        }
    }
    return false;
}

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    d_ll(n)
    vector<string> board(n);
    string s(n,'.');
    f1(i,0,n,1)
    {
        board[i] = s;
    }
    N_Queen(0,board,n);
}