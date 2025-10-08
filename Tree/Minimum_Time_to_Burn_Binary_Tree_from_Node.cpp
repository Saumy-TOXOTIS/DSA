#include <bits/stdc++.h>
using namespace std;

/*
 Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int minTime(TreeNode* root,TreeNode* startNode)
    {
        unordered_map<TreeNode*,TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = nullptr;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(node->left)
            {
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right)
            {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        // parent[node] -> parent of node
        unordered_map<TreeNode*,bool> visited;
        q.push(startNode);
        visited[startNode] = true;
        int time = 0;
        while(!q.empty())
        {
            int size = q.size();
            bool flag = false;
            for(int i = 0;i < size;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited[node->left])
                {
                    flag = true;
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right])
                {
                    flag = true;
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if(parent[node] && !visited[parent[node]])
                {
                    flag = true;
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
            if(flag)
            {
                time++;
            }
        }
        return time;
    }
};