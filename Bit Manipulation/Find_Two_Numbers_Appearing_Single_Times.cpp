#include <bits/stdc++.h>
using namespace std;

vector<int> findTwoOddAppearingNumbers(const vector<int>& arr)
{
    int xor_sum = 0;
    for(int num : arr)
    {
        xor_sum ^= num;
    }
    // 2. Find a "distinguishing feature". This is any bit that is set in xor_sum.
    // We choose the rightmost set bit. This bit is 1 for one target and 0 for the other.
    // The trick `x & -x` isolates the rightmost set bit, -xor_sum is the 2's complement, which is ~xor_sum + 1. This operation flips all the bits up to and including the rightmost '1', leaving only that bit set.
    int set_bit = xor_sum&-xor_sum;
    int x = 0;
    int y = 0;
    // 3. Filter and reduce. Partition the original array virtually based on the distinguishing feature.
    // All pairs will be in the same partition, cancelling out.
    // The two target numbers (x and y) will be in different partitions.
    for(int num : arr)
    {
        if((num & set_bit) != 0)
        {
            // This number has the distinguishing feature. Belongs to x's group.
            x ^= num;
        }
        else
        {
            // This number does not have the feature. Belongs to y's group.
            y ^= num;
        }
    }
    return {x, y};
}

int main()
{
    vector<int> arr = {4,2,4,5,2,3,3,1};
    vector<int> result = findTwoOddAppearingNumbers(arr);
    cout<<"The two numbers appearing an odd number of times are: "<<result[0]<<" and "<<result[1]<<endl;return 0;
}