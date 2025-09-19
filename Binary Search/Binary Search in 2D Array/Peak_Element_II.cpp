#include <bits/stdc++.h>
using namespace std;

vector<int> findPeakGrid(vector<vector<int>>& mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int low = 0;
    int high = m - 1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        bool shrinkLeft = false;
        for(int i = 0;i < n;i++)
        {
            if(i == 0 && i == n - 1)
            {
                if(mid == 0 && mid == m - 1)
                {
                    return {i,mid};
                }
                else if(mid == 0)
                {
                    if(mat[i][mid] > mat[i][mid + 1])
                    {
                        return {i,mid};
                    }
                    else
                    {
                        shrinkLeft = true;
                        break;
                    }
                }
                else if(mid == m - 1)
                {
                    if(mat[i][mid] > mat[i][mid - 1])
                    {
                        return {i,mid};
                    }
                    else
                    {
                        shrinkLeft = false;
                        break;
                    }
                }
                else
                {
                    if(mat[i][mid] > mat[i][mid - 1] && mat[i][mid] > mat[i][mid + 1])
                    {
                        return {i,mid};
                    }
                    else if(mat[i][mid - 1] > mat[i][mid])
                    {
                        shrinkLeft = false;
                        break;
                    }
                    else
                    {
                        shrinkLeft = true;
                        break;
                    }
                }
            }
            else if(i == 0)
            {
                if(mat[i][mid] > mat[i + 1][mid])
                {
                    if(mid == 0 && mid == m - 1)
                    {
                        return {i,mid};
                    }
                    else if(mid == 0)
                    {
                        if(mat[i][mid] > mat[i][mid + 1])
                        {
                            return {i,mid};
                        }
                        else
                        {
                            shrinkLeft = true;
                            break;
                        }
                    }
                    else if(mid == m - 1)
                    {
                        if(mat[i][mid] > mat[i][mid - 1])
                        {
                            return {i,mid};
                        }
                        else
                        {
                            shrinkLeft = false;
                            break;
                        }
                    }
                    else
                    {
                        if(mat[i][mid] > mat[i][mid - 1] && mat[i][mid] > mat[i][mid + 1])
                        {
                            return {i,mid};
                        }
                        else if(mat[i][mid - 1] > mat[i][mid])
                        {
                            shrinkLeft = false;
                            break;
                        }
                        else
                        {
                            shrinkLeft = true;
                            break;
                        }
                    }
                }
            }
            else if(i == n - 1)
            {
                if(mat[i][mid] > mat[i - 1][mid])
                {
                    if(mid == 0 && mid == m - 1)
                    {
                        return {i,mid};
                    }
                    else if(mid == 0)
                    {
                        if(mat[i][mid] > mat[i][mid + 1])
                        {
                            return {i,mid};
                        }
                        else
                        {
                            shrinkLeft = true;
                            break;
                        }
                    }
                    else if(mid == m - 1)
                    {
                        if(mat[i][mid] > mat[i][mid - 1])
                        {
                            return {i, mid};
                        }
                        else
                        {
                            shrinkLeft = false;
                            break;
                        }
                    }
                    else
                    {
                        if(mat[i][mid] > mat[i][mid - 1] && mat[i][mid] > mat[i][mid + 1])
                        {
                            return {i,mid};
                        }
                        else if(mat[i][mid - 1] > mat[i][mid])
                        {
                            shrinkLeft = false;
                            break;
                        }
                        else
                        {
                            shrinkLeft = true;
                            break;
                        }
                    }
                }
            }
            else
            {
                if(mat[i][mid] > mat[i - 1][mid] && mat[i][mid] > mat[i + 1][mid])
                {
                    if(mid == 0 && mid == m - 1)
                    {
                        return {i,mid};
                    }
                    else if(mid == 0)
                    {
                        if(mat[i][mid] > mat[i][mid + 1])
                        {
                            return {i,mid};
                        }
                        else
                        {
                            shrinkLeft = true;
                            break;
                        }
                    }
                    else if(mid == m - 1)
                    {
                        if(mat[i][mid] > mat[i][mid - 1])
                        {
                            return {i,mid};
                        }
                        else
                        {
                            shrinkLeft = false;
                            break;
                        }
                    }
                    else
                    {
                        if(mat[i][mid] > mat[i][mid - 1] && mat[i][mid] > mat[i][mid + 1])
                        {
                            return {i,mid};
                        }
                        else if(mat[i][mid - 1] > mat[i][mid])
                        {
                            shrinkLeft = false;
                            break;
                        }
                        else
                        {
                            shrinkLeft = true;
                            break;
                        }
                    }
                }
            }
        }
        if(shrinkLeft)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return {-1,-1};
}