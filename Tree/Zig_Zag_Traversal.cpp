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
private:
    vector<vector<int>> levelNodes;
    void levelOrder(TreeNode *root)
    {
        levelNodes.clear();
        queue<TreeNode *> q;
        if(root == NULL)
        {
            return;
        }
        q.push(root);
        int randomiser = 1;
        while(!q.empty())
        {
            int n = q.size();
            vector<int> level;
            for(int i = 0;i < n;i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if(node->left != NULL)
                {
                    q.push(node->left);
                }
                if(node->right != NULL)
                {
                    q.push(node->right);
                }
                level.push_back(node->val);
            }
            if(randomiser == 1)
            {
                levelNodes.push_back(level);
                randomiser = 0;
            }
            else
            {
                reverse(level.begin(),level.end());
                levelNodes.push_back(level);
                randomiser = 1;
            }
        }
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        levelOrder(root);
        return levelNodes;
    }
};