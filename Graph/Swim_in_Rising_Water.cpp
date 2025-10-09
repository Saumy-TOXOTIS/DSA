#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class disjoint_set
{
    public:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    disjoint_set(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0;i <= n;i++)
        {
            parent[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }
    //constructor
    int find_ultimate_parent(int node)
    {
        if(node == parent[node])
        {
            return node;
        }
        return (parent[node] = find_ultimate_parent(parent[node]));
    }
    //find ultimate parent of given node
    void union_by_rank(int first_vertex,int second_vertex)
    {
        int upfv = find_ultimate_parent(first_vertex);
        int upsv = find_ultimate_parent(second_vertex);
        if(upfv == upsv)
        {
            return;
        }
        if(rank[upfv] < rank[upsv])
        {
            parent[upfv] = upsv;
        }
        else if(rank[upfv] > rank[upsv])
        {
            parent[upsv] = upfv;
        }
        else if(rank[upfv] == rank[upsv])
        {
            parent[upsv] = upfv;
            rank[upfv]++;
        }
    }
    void union_by_size(int first_vertex,int second_vertex)
    {
        int upfv = find_ultimate_parent(first_vertex);
        int upsv = find_ultimate_parent(second_vertex);
        if(upfv == upsv)
        {
            return;
        }
        if(size[upfv] < size[upsv])
        {
            parent[upfv] = upsv;
            size[upsv] += size[upfv];
        }
        else if(size[upfv] > size[upsv])
        {
            parent[upsv] = upfv;
            size[upfv] += size[upsv];
        }
        else if(size[upfv] == size[upsv])
        {
            parent[upsv] = upfv;
            size[upfv] += size[upsv];
        }
    }
};

class Solution
{
public:
    int swimInWater(vector<vector<int>>& grid)
    {
        int n = grid.size();
        disjoint_set ds(n*n);
        vector<pair<int,pair<int,int>>> arr;
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                arr.push_back({grid[i][j],{i,j}});
            }
        }
        sort(arr.begin(),arr.end());
        for(auto item : arr)
        {
            int i = item.second.first;
            int j = item.second.second;
            visited[i][j] = true;
            for(int k = 0;k < 4;k++)
            {
                int nrow = i + delrow[k];
                int ncol = j + delcol[k];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && visited[nrow][ncol])
                {
                    int node = i*n + j;
                    int adjnode = nrow*n + ncol;
                    ds.union_by_rank(node,adjnode);
                }
            }
            if(ds.find_ultimate_parent(0) == ds.find_ultimate_parent(n*n - 1))
            {
                return item.first;
            }
        }
        return -1;
    }
};