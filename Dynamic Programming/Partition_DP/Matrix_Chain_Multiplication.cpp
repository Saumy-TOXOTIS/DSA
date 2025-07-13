#include <bits/stdc++.h>
using namespace std;

//Rules of Partition DP :
/*
1. Start with entire portion/block/array and represent them by f(i,j) where i -> starting point and j -> ending point
2. Try all partitions ( probably run a loop to try out all partitions )
3. Return the best possible 2 partitons ( or whatever asked accordingly )
*/

/*
n = 5 ( 4 matrices )

array = [10,20,30,40,50]
         -----
            -----
               -----
                  -----
            A  B  C  D
            i        j
            1     (n - 1)
ABCD -> goal multiplication

f(1,(n - 1),array) -> minimum multiplications to multiply matrices from 1 to (n - 1)
{
    if(i == j)
    {
        return 0;
    }
    int ans = 1e9;
    for(int j = i;k < j;k++)
    {
        ans = min(ans,array[i - 1]*array[k]*array[j] + f(i,k,array) + f(k + 1,j,array));
    }
    return ans;
}
*/

int f(vector<int>& arr,int i,int j,vector<vector<int>>& dp)
{
    if(i == j)
    {
        return 0;
    }
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = 1e9;
    for(int k = i;k < j;k++)
    {
        ans = min(ans,arr[i - 1]*arr[k]*arr[j] + f(arr,i,k,dp) + f(arr,k + 1,j,dp));
    }
    return dp[i][j] = ans;
}

int matrixMultiplication(vector<int>& arr, int N)
{
    vector<vector<int>> dp(N,vector<int>(N,0));
    // return f(arr,1,N - 1,dp);
    for(int i = N - 2;i >= 1;i--)
    {
        for(int j = i + 1;j < N;j++)
        {
            int ans = 1e9;
            for(int k = i;k < j;k++)
            {
                ans = min(ans,arr[i - 1]*arr[k]*arr[j] + dp[i][k] + dp[k + 1][j]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[1][N - 1];
}

int main()
{
	vector<int> arr = {10, 20, 30, 40, 50};
	int n = arr.size();
    // (n - 1) matrices
    // for any ith matrix the dimension is (A[i - 1] x A[i])
	cout<<"The minimum number of operations is "<<matrixMultiplication(arr,n);
	return 0;
}