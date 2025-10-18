#include <bits/stdc++.h>
using namespace std;

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
    TreeNode* buildTreeHelper(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,map<int,int>& mp)
    {
        if(preStart > preEnd || inStart > inEnd)
        {
            return NULL;
        }
        int rootValue = preorder[preStart];
        TreeNode* root = new TreeNode(rootValue);
        int rootIndex = mp[rootValue];
        int leftSubtreeSize = rootIndex - inStart;
        root->left = buildTreeHelper(preorder,preStart + 1,preStart + leftSubtreeSize,inorder,inStart,rootIndex - 1,mp);
        root->right = buildTreeHelper(preorder,preStart + leftSubtreeSize + 1,preEnd,inorder,rootIndex + 1,inEnd,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder)
    {
        // preorder : root -> left -> right
        // inorder  : left -> root -> right
        map<int,int> mp;
        for(int i = 0;i < inorder.size();i++)
        {
            mp[inorder[i]] = i;
        }
        TreeNode* root = buildTreeHelper(preorder,0,preorder.size() - 1,inorder,0,inorder.size() - 1,mp);
        return root;
    }
};