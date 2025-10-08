#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

class Solution
{
public:
    vector<vector<int>> findAllPaths(TreeNode* root,int node)
    {
        vector<vector<int>> ans;
        if(!root)
        {
            return ans;
        }
        vector<int> path;
        function<void(TreeNode*)> dfs = [&](TreeNode* curr)
        {
            if(!curr)
            {
                return;
            }
            path.push_back(curr->data);
            if(curr->data == node)
            {
                ans.push_back(path);
            }
            dfs(curr->left);
            dfs(curr->right);
            path.pop_back();
        };
        dfs(root);
        return ans;
    }

	vector<int> findPathToNode(TreeNode* root,int node)
    {
        vector<int> ans;
        if(!root)
        {
            return ans;
        }
        map<int,int> parent;
        parent[root->data] = -1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left)
            {
                parent[temp->left->data] = temp->data;
                q.push(temp->left);
            }
            if(temp->right)
            {
                parent[temp->right->data] = temp->data;
                q.push(temp->right);
            }
        }
        int curr = node;
        while(curr != -1)
        {
            ans.push_back(curr);
            curr = parent[curr];
        }
        reverse(ans.begin(),ans.end());
        return ans;
	}
};