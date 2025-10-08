#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSumTree(TreeNode* root)
    {
        if(!root)
        {
            return true;
        }
        int leftSum = 0;
        int rightSum = 0;
        if(root->left)
        {
            leftSum = root->left->val;
        }
        if(root->right)
        {
            rightSum = root->right->val;
        }
        if(root->val != leftSum + rightSum)
        {
            return false;
        }
        return isSumTree(root->left) && isSumTree(root->right);
    }

    void convertToSumTree(TreeNode* root)
    {
        // we can not decrement value of a node, we can only incremenet its value
        if(!root)
        {
            return;
        }
        convertToSumTree(root->left);
        convertToSumTree(root->right);
        int leftSum = 0;
        int rightSum = 0;
        if(root->left)
        {
            leftSum = root->left->val;
        }
        if(root->right)
        {
            rightSum = root->right->val;
        }
        if(root->val < leftSum + rightSum)
        {
            root->val = leftSum + rightSum;
        }
        else
        {
            int diff = root->val - (leftSum + rightSum);
            if(root->left)
            {
                root->left->val += diff;
                convertToSumTree(root->left);
            }
            else if(root->right)
            {
                root->right->val += diff;
                convertToSumTree(root->right);
            }
        }
    }
};