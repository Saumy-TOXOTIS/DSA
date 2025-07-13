#include <bits/stdc++.h>
using namespace std;

// Count number of substring containing all three charecters 'a', 'b' and 'c'

class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.length();
        int right = 0;
        int a = -1;
        int b = -1;
        int c = -1;
        int count = 0;
        while(right < n)
        {
            if(s[right] == 'a')
            {
                a = right;
            }
            else if(s[right] == 'b')
            {
                b = right;
            }
            else
            {
                c = right;
            }
            count += min({a,b,c}) + 1;
        }
        return count;
    }
};