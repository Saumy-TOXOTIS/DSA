#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findLexSmallestString(string s,int a,int b)
    {
        int n = s.length(); // n is even
        unordered_map<string,bool> visited;
        queue<string> q;
        q.push(s);
        visited[s] = true;
        string ans = s;
        while(!q.empty())
        {
            string curr = q.front();
            q.pop();
            ans = min(ans,curr);
            string rotated = curr.substr(n - b) + curr.substr(0, n - b);
            if(!visited[rotated])
            {
                visited[rotated] = true;
                q.push(rotated);
            }
            string added = curr;
            for(int i = 1; i < n; i += 2)
            {
                added[i] = (added[i] - '0' + a) % 10 + '0';
            }
            if(!visited[added])
            {
                visited[added] = true;
                q.push(added);
            }
        }
        return ans;
    }
};