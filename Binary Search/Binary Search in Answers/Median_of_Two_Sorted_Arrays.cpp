#include <bits/stdc++.h>
using namespace std;

int findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    if(n > m)
    {
        return findMedianSortedArrays(nums2,nums1);
    }
    // assuming nums1 is smaller than nums2 in length
    int low = 0;
    int high = n;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        int cut1 = mid; // cut from nums1
        int cut2 = (n + m + 1)/2 - cut1; // cut from nums2
        // median could be either last element from cut1 or cut2 if but cut1 and cut2 are real
        int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
        int right1 = (cut1 == n) ? INT_MAX : nums1[cut1];
        int right2 = (cut2 == m) ? INT_MAX : nums2[cut2];
        // right1 should be greater than left2 and right2 should be greater than left1
        if(left1 <= right2 && left2 <= right1)
        {
            // correct cut
            if((n + m) % 2 == 0)
            {
                return (max(left1,left2) + min(right1,right2))/2.0;
            }
            else
            {
                return max(left1,left2);
            }
        }
        else if(left1 > right2)
        {
            high = mid - 1;
        }
        else if(left2 > right1)
        {
            low = mid + 1;
        }
    }
}