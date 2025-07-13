#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution
{
private:
    unordered_map<string,int> mapping;
    vector<vector<string>> ans;
    string b;
    ll sz;
    void DFS(string word,vector<string>& seq)
    {
        if(word == b)
        {
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps = mapping[word];
        for(ll j = 0;j < sz;j++)
        {
            char initial = word[j];
            for(ll i = 0;i < 26;i++)
            {
                word[j] = 'a' + i;
                if(mapping.find(word) != mapping.end() && mapping[word] + 1 == steps)
                {
                    seq.push_back(word);
                    DFS(word,seq);
                    seq.pop_back();
                }
            }
            word[j] = initial;
        }
    }
public:
    vector<vector<string>> findLadders(string wstart, string wend, vector<string>& wordsList)
    {
        b = wstart;
        unordered_set<string> words(wordsList.begin(), wordsList.end());
        queue<string> q;
        q.push(wstart);
        mapping[wstart] = 1;
        words.erase(wstart);
        sz = wstart.size();
        while(!q.empty())
        {
            string cur_word = q.front();
            ll cur_dist = mapping[cur_word];
            q.pop();
            if(cur_word == wend)
            {
                break;
            }
            for(ll j = 0;j < sz;j++)
            {
                char initial = cur_word[j];
                for(ll i = 0;i < 26;i++)
                {
                    cur_word[j] = 'a' + i;
                    if(words.count(cur_word))
                    {
                        words.erase(cur_word);
                        q.push(cur_word);
                        mapping[cur_word] = cur_dist + 1;
                    }
                }
                cur_word[j] = initial;
            }
        }
        if(mapping.find(wend) != mapping.end())
        {
            vector<string> seq;
            seq.push_back(wend);
            DFS(wend,seq);
        }
        return ans;
    }
};