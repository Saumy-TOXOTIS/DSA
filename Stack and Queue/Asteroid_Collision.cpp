#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        int n = asteroids.size();
        vector<int> ans;
        stack<int> s;
        vector<int> possible(n,1);
        for(int i = 0;i < n;i++)
        {
            if(asteroids[i] < 0)
            {
                while(!s.empty() && asteroids[s.top()] < abs(asteroids[i]))
                {
                    possible[s.top()] = 0;
                    s.pop();
                }
                if(!s.empty())
                {
                    possible[i] = 0;
                    if(asteroids[s.top()] == abs(asteroids[i]))
                    {
                        possible[s.top()] = 0;
                        s.pop();
                    }
                }
            }
            else
            {
                s.push(i);
            }
        }
        for(int i = 0;i < n;i++)
        {
            if(possible[i])
            {
                ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }
};