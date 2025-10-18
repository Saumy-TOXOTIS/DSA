#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> lexicalOrder(int num)
    {
        vector<int> result;
        function<void(int)> DFS = [&](int n)
        {
            if(n > num)
            {
                return;
            }
            result.push_back(n);
            for(int i = 0;i < 10;i++)
            {
                int next = n*10 + i;
                if(next > 0 && next <= num)
                {
                    DFS(next);
                }
            }
        };
        for(int j = 1;j < 10;j++)
        {
            DFS(j);
        }
        return result;
    }
};