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
    void inorder(TreeNode* root,int &k,int &ans)
    {
        if(!root)
        {
            return;
        }
        inorder(root->left,k,ans);
        k--;
        if(k==0)
        {
            ans = root->val;
            return;
        }
        inorder(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root,int k)
    {
        int ans = -1;
        inorder(root,k,ans);
        return ans;
    }
};