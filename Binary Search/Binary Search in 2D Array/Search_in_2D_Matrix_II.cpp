#include <bits/stdc++.h>
using namespace std;

/*
All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.
*/

// TC : O(min*(n,m)*log(n + m))
bool searchMatrix_v1(vector<vector<int>>& matrix,int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0;
    int high = n + m - 2;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        int i0 = max(0,mid - m + 1);
        int i1 = min(n - 1,mid);
        int mn = INT_MAX;
        int mx = INT_MIN;
        bool found = false;
        for(int i = i0;i <= i1;i++)
        {
            int j = mid - i;
            mn = min(mn,matrix[i][j]);
            mx = max(mx,matrix[i][j]);
            if(matrix[i][j] == target)
            {
                found = true;
                break;
            }
        }
        if(found)
        {
            return true;
        }
        else if(target > mx)
        {
            low = mid + 1;
        }
        else if(target < mn)
        {
            high = mid - 1;
        }
        else
        {
            int L = mid - 1;
            while(L >= low)
            {
                int li0 = max(0,L - m + 1);
                int li1 = min(n - 1,L);
                int lmn = INT_MAX;
                int lmx = INT_MIN;
                bool lfound = false;
                for(int i = li0;i <= li1;i++)
                {
                    int j = L - i;
                    lmn = min(lmn,matrix[i][j]);
                    lmx = max(lmx,matrix[i][j]);
                    if(matrix[i][j] == target)
                    {
                        lfound = true;
                        break;
                    }
                }
                if(lfound)
                {
                    return true;
                }
                if(target < lmn || target > lmx)
                {
                    break;
                }
                L--;
            }
            int R = mid + 1;
            while(R <= high)
            {
                int ri0 = max(0,R - m + 1);
                int ri1 = min(n - 1,R);
                int rmn = INT_MAX;
                int rmx = INT_MIN;
                bool rfound = false;
                for(int i = ri0;i <= ri1;i++)
                {
                    int j = R - i;
                    rmn = min(rmn,matrix[i][j]);
                    rmx = max(rmx,matrix[i][j]);
                    if(matrix[i][j] == target)
                    {
                        rfound = true;
                        break;
                    }
                }
                if(rfound)
                {
                    return true;
                }
                if(target < rmn || target > rmx)
                {
                    break;
                }
                R++;
            }
            return false;
        }
    }
    return false;
}

// TC : O(n + m)
bool searchMatrix_v2(vector<vector<int>>& matrix,int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int i = 0;
    int j = m - 1;
    while((i < n) && (j >= 0))
    {
        if(matrix[i][j] == target)
        {
            return true;
        }
        else if(matrix[i][j] > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}

// TC : O(n*log(m))
bool searchMatrix_v3(vector<vector<int>>& matrix,int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i = 0;i < n;i++)
    {
        int low = 0;
        int high = m - 1;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(matrix[i][mid] == target)
            {
                return true;
            }
            else if(matrix[i][mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return false;
}