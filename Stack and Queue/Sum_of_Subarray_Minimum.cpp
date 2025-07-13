#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

class Solution
{
private:
    vector<int> findNSE(vector<int>& arr)
    {
        int n = arr.size();
        stack<int> s;
        vector<int> ans(n,n);
        for(int i = n - 1;i >= 0;i--)
        {
            while(!s.empty() && arr[s.top()] >= arr[i])
            {
                s.pop();
            }
            if(!s.empty())
            {
                ans[i] = s.top();
            }
            s.push(i);
        }
        return ans;
    }
    vector<int> findPSEE(vector<int>& arr)
    {
        int n = arr.size();
        stack<int> s;
        vector<int> ans(n,-1);
        for(int i = 0;i < n;i++)
        {
            while(!s.empty() && arr[s.top()] > arr[i])
            {
                s.pop();
            }
            if(!s.empty())
            {
                ans[i] = s.top();
            }
            s.push(i);
        }
        return ans;
    }
public:
    int sumSubarrayMins(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);
        int ans = 0;
        for(int i = 0;i < n;i++)
        {
            int left = i - psee[i];
            int right = nse[i] - i;
            ans = (ans + (left*right*1LL*arr[i])%mod)%mod;
        }
        return ans;
    }
};