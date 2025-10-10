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
    TreeNode* ceilInBST(TreeNode *root,int key)
    {
        TreeNode* ceil = nullptr;
        while(root)
        {
            if(root->val >= key)
            {
                ceil = root;
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        return ceil;
    }
};