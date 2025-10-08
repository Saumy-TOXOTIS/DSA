#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    vector<int> distanceK(TreeNode* root,TreeNode* target, int k)
    {
        vector<int> ans;
        if(!root)
        {
            return ans;
        }
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
        q.push(target);
        visited[target] = true;
        int curr_level = -1;
        while(!q.empty())
        {
            int size = q.size();
            curr_level++;
            if(curr_level == k + 1)
            {
                break;
            }
            for(int i = 0;i < size;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(curr_level == k)
                {
                    ans.push_back(node->val);
                }
                if(node->left && !visited[node->left])
                {
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right])
                {
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if(parent[node] && !visited[parent[node]])
                {
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
        }
        return ans;
    }
};