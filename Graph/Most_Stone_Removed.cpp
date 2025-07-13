#include <bits/stdc++.h>
using namespace std;

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
    int removeStones(vector<vector<int>>& stones)
    {
        int n = stones.size(); // number of stones
        int maxRow = 0;
        int maxCol = 0;
        for(int i = 0;i < n;i++)
        {
            maxRow = max(maxRow,stones[i][0]);
            maxCol = max(maxCol,stones[i][1]);
        }
        unordered_map<int,int> stoneNodes;
        disjoint_set ds(maxRow + maxCol + 1);
        for(int i = 0;i < n;i++)
        {
            int nodeRow = stones[i][0];
            int nodeCol = stones[i][1] + maxRow + 1;
            ds.union_by_size(nodeRow,nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        int count = 0;
        for(auto item : stoneNodes)
        {
            if(ds.find_ultimate_parent(item.first) == item.first)
            {
                count++;
            }
        }
        return n - count;
    }
};