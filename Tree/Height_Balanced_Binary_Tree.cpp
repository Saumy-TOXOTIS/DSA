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
    int recursion(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int left = recursion(root->left);
        int right = recursion(root->right);
        if(abs(left - right) > 1)
        {
            return -1;
        }
        return (1 + max(left,right));
    }
    bool check(TreeNode* root)
    {
        if(root == NULL)
        {
            return true;
        }
        int left = recursion(root->left);
        int right = recursion(root->right);
        if(abs(left - right) > 1 || (left == -1 || right == -1))
        {
            return false;
        }
        bool lefth = check(root->left);
        bool righth = check(root->right);
        return (lefth && righth);
    }
public:
    bool isBalanced(TreeNode* root)
    {
        return check(root);
    }
};