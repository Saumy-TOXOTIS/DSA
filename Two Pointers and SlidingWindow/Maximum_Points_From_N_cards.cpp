#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int>& a, int k)
    {
        int n = a.size();
        int sum = 0;
        int max_sum = 0;
        int left_right = k - 1;
        int right_left = n;
        for(int i = 0;i < k;i++)
        {
            sum += a[i];
        }
        max_sum = max(max_sum,sum);
        while(left_right >= 0)
        {
            sum -= a[left_right];
            left_right--;
            right_left--;
            sum += a[right_left];
            max_sum = max(max_sum,sum);
        }
        return max_sum;
    }
};