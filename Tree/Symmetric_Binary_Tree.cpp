#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    bool recursion(TreeNode* L,TreeNode* R)
    {
        if(L == NULL && R == NULL)
        {
            return true;
        }
        if(L == NULL || R == NULL)
        {
            return false;
        }
        return ((L->val == R->val)&&recursion(L->right,R->left)&&recursion(L->left,R->right));
    }
public:
    bool isSymmetric(TreeNode* root)
    {
        if(root == NULL)
        {
            return true;
        }
        TreeNode* L = root->left;
        TreeNode* R = root->right;
        return recursion(L,R);
    }
};