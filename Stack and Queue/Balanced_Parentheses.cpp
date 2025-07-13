#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        map<char,char> mapping;
        mapping[')'] = '(';
        mapping['}'] = '{';
        mapping[']'] = '[';
        stack<char> dummy;
        for(int i = 0;i < s.length();i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                dummy.push(s[i]);
            }
            else
            {
                if(dummy.size() == 0)
                {
                    return false;
                }
                if(dummy.top() == mapping[s[i]])
                {
                    dummy.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if(dummy.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};