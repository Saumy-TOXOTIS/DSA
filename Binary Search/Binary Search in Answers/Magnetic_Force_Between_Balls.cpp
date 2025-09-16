#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool checker(vector<int>& position,int mid,int m)
    {
        int count = 1;
        int last = position[0];
        for(int i = 1;i < position.size();i++)
        {
            if(position[i] - last >= mid)
            {
                count++;
                last = position[i];
            }
        }
        if(count >= m)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
public:
    int maxDistance(vector<int>& position,int m)
    {
        int n = position.size();
        sort(position.begin(),position.end());
        int low = 1;
        int high = position[n - 1] - position[0];
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(checker(position,mid,m))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return high;
    }
};