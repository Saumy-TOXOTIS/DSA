#include "template.hpp"
ll n, m, source;
string wstart, wend;
const ll N = 2e5;
set<string> words;
vector<pair<ll,ll>> graph[N + 1];
v(ll) visited(N + 1,0);
v(ll) path(N + 1,0);
v(ll) dist(N + 1,lMAX);
v(ll) indegree(N + 1,0);
queue<pair<string,ll>> q;

/*########### Extra Functions ###########*/

/*################ Code #################*/

TOXOTIS
{
    // Fast_IO
    cin>>n;
    for(ll i = 0;i < n;i++)
    {
        string var;
        cin>>var;
        words.insert(var);
    }
    cin>>wstart>>wend;
    q.push({wstart,1});
    words.erase(wstart);
    ll min_dist = lMAX;
    while(!q.empty())
    {
        string cur_word = q.front().first;
        ll cur_dist = q.front().second;
        q.pop();
        min_dist = cur_dist;
        if(cur_word == wend)
        {
            break;
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
    cout<<min_dist<<endl;
}