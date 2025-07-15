#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {
        int low = 0;
        int high = 0;
        for(auto item : s)
        {
            if(item == '(')
            {
                low++;
                high++;
            }
            else if(item == ')')
            {
                low--;
                high--;
            }
            else if(item == '*')
            {
                low--;
                high++;
            }
            if(high < 0)
            {
                return false;
            }
            low = max(0,low);
        }
        return low == 0;
    }
};