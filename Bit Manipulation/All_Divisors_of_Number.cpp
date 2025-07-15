#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> allDivisors(int n)
    {
        vector<int> isPrime(n/32 + 2,0);
        isPrime[0] = isPrime[0]|(1<<0);
        isPrime[0] = isPrime[0]|(1<<1);
        for(long long i = 2;i*i <= n;++i) 
        {
            int idx = i/32;
            int pos = i%32;
            if((isPrime[idx]&(1<<pos)) == 0)
            {
                for(long long j = i*i;j <= n;j += i)
                {
                    int j_idx = j / 32;
                    int j_pos = j % 32;
                    isPrime[j_idx] = isPrime[j_idx]|(1 << j_pos);
                }
            }
        }
        vector<int> primeFactors;
        for(int i = 2;i <= n;i++)
        {
            int idx = i/32;
            int pos = i%32;
            if(((isPrime[idx]&(1<<pos)) == 0) && (n%i == 0))
            {
                primeFactors.push_back(i);
            }
        }
        vector<int> divisors;
        int totalDivisors = primeFactors.size();
        int totalSubsets = 1<<totalDivisors;
        for(int i = 0;i < totalSubsets;i++)
        {
            int multiple = 1;
            for(int j = 0;j < totalDivisors;j++)
            {
                if((i>>j)&1)
                {
                    multiple = multiple*primeFactors[j];
                }
            }
            divisors.push_back(multiple);
        }
        return divisors;
    }
};