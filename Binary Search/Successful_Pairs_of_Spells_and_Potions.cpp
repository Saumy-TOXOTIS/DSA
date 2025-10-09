#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,long long success)
    {
        int n = spells.size();
        int m = potions.size();
        vector<int> ans(n, 0);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++)
        {
            long long target = (success + spells[i] - 1) / spells[i];
            int idx = lower_bound(potions.begin(), potions.end(), target) - potions.begin();
            ans[i] = m - idx;
        }
        return ans;
    }
};