#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {
        vector<int> ans;
        for(int i = 1;i <= n - k;i++)
        {
            ans.push_back(i);
        }
        int left = n - k + 1;
        int right = n;
        while(left < right)
        {
            ans.push_back(right);
            ans.push_back(left);
            left++;
            right--;
        }
        if(left == right)
        {
            ans.push_back(left);
        }
        return ans;
    }
};