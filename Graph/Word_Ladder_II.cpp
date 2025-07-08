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

/*########### Extra Functions ###########*/

// Improve the logic accordingly for word ladder II problem

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
    // Logic goes here
}