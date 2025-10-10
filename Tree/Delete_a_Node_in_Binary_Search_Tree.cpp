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
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if(!root)
        {
            return nullptr;
        }
        if(root->val == key)
        {
            if(!root->left && !root->right)
            {
                return nullptr;
            }
            else if(!root->left)
            {
                return root->right;
            }
            else if(!root->right)
            {
                return root->left;
            }
            else
            {
                TreeNode* temp = root->right;
                while(temp->left)
                {
                    temp = temp->left;
                }
                root->val = temp->val;
                root->right = deleteNode(root->right,temp->val);
                return root;
            }
        }
        else
        {
            if(root->val > key)
            {
                root->left = deleteNode(root->left,key);
            }
            else
            {
                root->right = deleteNode(root->right,key);
            }
        }
        return root;
    }
};