#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Why 32? Because we are working on 32-bits integers
    int countPrimes(int n)
    {
        if(n < 2)
        {
            return 0;
        }
        vector<int> isPrime(n/32 + 2,0);
        for(long long i = 2;i*i < n;++i) 
        {
            int idx = i/32;
            int pos = i%32;
            if((isPrime[idx]&(1<<pos)) == 0)
            {
                for(long long j = i*i;j < n;j += i)
                {
                    int j_idx = j / 32;
                    int j_pos = j % 32;
                    isPrime[j_idx] = isPrime[j_idx]|(1 << j_pos);
                }
            }
        }
        int ans = 0;
        for(int i = 2;i < n;i++)
        {
            int idx = i/32;
            int pos = i%32;
            if((isPrime[idx]&(1<<pos)) == 0)
            {
                ans++;
            }
        }
        return ans;
    }
};