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

// inorder of a binary search tree is sorted array
// so we can do inorder traversal and keep a count of nodes visited

class Solution
{
public:
    bool recursion(TreeNode* root,long long low,long long high)
    {
        if(!root)
        {
            return true;
        }
        if((long long)root->val <= low || (long long)root->val >= high)
        {
            return false;
        }
        else
        {
            return (recursion(root->left,low,(long long)root->val) && recursion(root->right,(long long)root->val,high));
        }
    }
    bool isValidBST(TreeNode* root)
    {
        return recursion(root,(long long)-1e12,(long long)1e12);
    }
};