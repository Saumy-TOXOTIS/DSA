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

//1st approach

//[NOTE] : Pass vector array's address in functions. And no MACROS for 'for' works correctly in specially recursive functions

void Permutate_1(vll& array,vll& ds,ll freq[])
{
    if(ds.size() == array.size())
    {
        for(auto element : ds)
        {
            cout<<element<<" ";
        }
        cout<<endl;
        return;
    }
    for(ll i = 0;i < array.size();i++)
    {
        if(!freq[i])
        {
            ds.push_back(array[i]);
            freq[i] = 1;
            Permutate_1(array,ds,freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

void Permutations_1(vll& array,ll start,ll end,vll& ds)
{
    if(start >= end)
    {
        vll dummy;
        ll freq[ds.size()] = {0};
        Permutate_1(ds,dummy,freq);
        return;
    }
    //Not pick up an item in Subsequence
    Permutations_1(array,start + 1,end,ds);
    //Pick up an item in Subsequence
    ds.push_back(array[start]);
    Permutations_1(array,start + 1,end,ds);
    ds.pop_back();
}

//2nd approach

void Permutate_2(vll& array,ll index,set<vll>& myset)
{
    if(index == array.size())
    {
        myset.insert(array);
        return;
    }
    for(ll i = 0;i < array.size();i++)
    {
        swap(array[i],array[index]);
        Permutate_2(array,index + 1,myset);
        swap(array[i],array[index]);
    }
}

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    d_ll(n)
    d_llVecArr(a,n)
    vll ds;
    ll freq[n] = {0};
    set<vll> myset;
    // Permutations_1(a,0,n,ds);
    Permutate_2(a,0,myset);
    for(auto element : myset)
    {
        for(auto items : element)
        {
            cout<<items<<" ";
        }
        cout<<endl;
    }
}