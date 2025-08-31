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
    int maxPath = -1e9;
    int recursion(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int left = max(0,recursion(root->left));
        int right = max(0,recursion(root->right));
        maxPath = max(maxPath,root->val + left + right);
        return (root->val + max(left,right));
    }
public:
    int maxPathSum(TreeNode* root)
    {
        recursion(root);
        return maxPath;
    }
};