#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<vector<int>>& points, long long D)
    {
        int n = points.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++)
        {
            if(color[i] == -1)
            {
                color[i] = 0;
                queue<int> q;
                q.push(i);
                while(!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    for(int v = 0; v < n; v++)
                    {
                        if(v == u) continue;
                        long long dist = llabs((long long)points[v][0] - points[u][0]) + llabs((long long)points[v][1] - points[u][1]);
                        if(dist < D)
                        {
                            if(color[v] == -1)
                            {
                                color[v] = 1 - color[u];
                                q.push(v);
                            }
                            else if(color[v] == color[u])
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }

    int maxPartitionFactor(vector<vector<int>>& points)
    {
        int n = points.size();
        if(n == 2)
        {
            return 0;
        }
        long long minx = LLONG_MAX, maxx = LLONG_MIN, miny = LLONG_MAX, maxy = LLONG_MIN;
        for(auto& p : points)
        {
            minx = min(minx, (long long)p[0]);
            maxx = max(maxx, (long long)p[0]);
            miny = min(miny, (long long)p[1]);
            maxy = max(maxy, (long long)p[1]);
        }
        long long low = 0, high = (maxx - minx) + (maxy - miny), ans = 0;
        while(low <= high)
        {
            long long mid = low + (high - low) / 2;
            if(check(points, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return (int)ans;
    }
};