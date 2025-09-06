#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool compare(string& a, string& b)
    {
        return a + b > b + a;
    }
public:
    string largestNumber(vector<int>& nums)
    {
        vector<string> s;
        s.reserve(nums.size());
        for(auto x : nums)
        {
            s.push_back(to_string(x));
        }
        sort(s.begin(),s.end(),compare);
        if(s[0] == "0")
        {
            return "0";
        }
        string ans;
        for(auto x : s)
        {
            ans += x;
        }
        return ans;
    }
};