#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix,int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0;
    int high = n*m - 1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        int rows = mid/m;
        int cols = mid%m;
        if(matrix[rows][cols] == target)
        {
            return true;
        }
        else if(matrix[rows][cols] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}