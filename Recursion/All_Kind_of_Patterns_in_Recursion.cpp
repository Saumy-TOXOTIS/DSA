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

//Prints only one answer
bool Print_Subsequence_of_Sum_k_only_one(vll array,ll start,ll end,ll sum,vll ds,ll checker)
{
    if(start >= end)
    {
        if(checker == sum)
        {
            for(auto element : ds)
            {
                cout<<element<<" ";
            }
            cout<<endl;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    //Not Pick up an Index into Subsequence
    if(Print_Subsequence_of_Sum_k_only_one(array,start + 1,end,sum,ds,checker))
    {
        return 1;
    }
    //Pick up an Index into Subsequence
    ds.push_back(array[start]);
    checker += array[start];
    if(Print_Subsequence_of_Sum_k_only_one(array,start + 1,end,sum,ds,checker))
    {
        return 1;
    }
    checker -= ds[ds.size() - 1];
    ds.pop_back();
    return 0;
}

//Prints all answers
void Print_Subsequence_of_Sum_k(vll array,ll start,ll end,ll sum,vll ds,ll checker,set<vll>& answers)
{
    if(start >= end)
    {
        if(checker == sum)
        {
            answers.insert(ds);
        }
        return;
    }
    //Not Pick up an Index into Subsequence
    Print_Subsequence_of_Sum_k(array,start + 1,end,sum,ds,checker,answers);
    //Pick up an Index into Subsequence
    ds.push_back(array[start]);
    checker += array[start];
    Print_Subsequence_of_Sum_k(array,start + 1,end,sum,ds,checker,answers);
    checker -= ds[ds.size() - 1];
    ds.pop_back();
}

//Counts Number of Subsequence with given sum
ll Count_Subsequence_of_Sum_k(vll array,ll start,ll end,ll sum,vll ds,ll checker)
{
    if(start >= end)
    {
        if(checker == sum)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    //Not Pick up an Index into Subsequence
    ll left = Count_Subsequence_of_Sum_k(array,start + 1,end,sum,ds,checker);
    //Pick up an Index into Subsequence
    ds.push_back(array[start]);
    checker += array[start];
    ll right = Count_Subsequence_of_Sum_k(array,start + 1,end,sum,ds,checker);
    checker -= ds[ds.size() - 1];
    ds.pop_back();
    return (left + right);
}

/*################ Code #################*/

TOXOTIS
{
    Fast_IO
    //use before taking any input
    d_ll(n) d_ll(k)
    d_llVecArr(a,n)
    vll ds;
    set<vll> answers;
    Print_Subsequence_of_Sum_k(a,0,n,k,ds,0,answers);
    for(auto element : answers)
    {
        for(auto items : element)
        {
            cout<<items<<" ";
        }
        cout<<endl;
    }
}