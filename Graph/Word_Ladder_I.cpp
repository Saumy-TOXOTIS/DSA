#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution
{
public:
    int ladderLength(string wstart, string wend, vector<string>& wordsList)
    {
        set<string> words(wordsList.begin(), wordsList.end());
        if(words.find(wend) == words.end())
        {
            return 0;
        }
        queue<pair<string,ll>> q;
        q.push({wstart,1});
        words.erase(wstart);
        while(!q.empty())
        {
            string cur_word = q.front().first;
            ll cur_dist = q.front().second;
            q.pop();
            if(cur_word == wend)
            {
                return cur_dist;
            }
            for(ll j = 0;j < cur_word.length();j++)
            {
                char initial = cur_word[j];
                for(ll i = 0;i < 26;i++)
                {
                    cur_word[j] = 'a' + i;
                    if(words.find(cur_word) != words.end())
                    {
                        words.erase(cur_word);
                        q.push({cur_word,cur_dist + 1});
                    }
                }
                cur_word[j] = initial;
            }
        }
        return 0;
    }
};