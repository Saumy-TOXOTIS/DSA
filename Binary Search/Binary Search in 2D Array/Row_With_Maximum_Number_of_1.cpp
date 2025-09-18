#include <bits/stdc++.h>
using namespace std;

int count1(vector<int>& row)
{
    int firstOccurence = lower_bound(row.begin(),row.end(),1) - row.begin();
    return row.size() - firstOccurence;
}

int rowWithMax1(vector<vector<int>>& mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int maxRowIndex = -1;
    int max1Count = 0;
    for(int i=0;i<n;i++)
    {
        int count = count1(mat[i]);
        if(count > max1Count)
        {
            max1Count = count;
            maxRowIndex = i;
        }
    }
    return maxRowIndex;
}