#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills)
    {
        map<int,int> mapping;
        for(auto item : bills)
        {
            mapping[item]++;
            if(item == 10)
            {
                if(mapping[5] > 0)
                {
                    mapping[5]--;
                }
                else
                {
                    return false;
                }
            }
            else if(item == 20)
            {
                if(mapping[10] > 0 && mapping[5] > 0)
                {
                    mapping[10]--;
                    mapping[5]--;
                }
                else if(mapping[5] > 2)
                {
                    mapping[5] -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};