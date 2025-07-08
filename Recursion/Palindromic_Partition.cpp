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

/*########### Extra Functions ###########*/

bool Check_Palindrome(string& s,ll start,ll end)
{
    while(start <= end)
    {
        if(s[start] != s[end])
        {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

void Palindromic_Partition(string& word,vector<vector<string>>& ans,vector<string>& part,ll index)
{
    if(index == word.length())
    {
        ans.push_back(part);
        return;
    }
    for(ll i = index;i < word.length();++i)
    {
        if(Check_Palindrome(word,index,i))
        {
            part.push_back(word.substr(index,i - index + 1));
            Palindromic_Partition(word,ans,part,index + 1);
            part.pop_back();
        }
    }
}

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    d_string(s)
    vector<vector<string>> ans;
    vector<string> part;
    Palindromic_Partition(s,ans,part,0);
    for(auto element : ans)
    {
        for(auto items : element)
        {
            cout<<items<<" ";
        }
        cout<<endl;
    }
}