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

class Solution
{
public:
    TreeNode* buildTreeHelper(vector<int>& inorder,int inStart,int inEnd,vector<int>& postorder,int postStart,int postEnd,map<int,int>& mp)
    {
        if(postStart > postEnd || inStart > inEnd)
        {
            return NULL;
        }
        int rootValue = postorder[postEnd];
        TreeNode* root = new TreeNode(rootValue);
        int rootIndex = mp[rootValue];
        int leftSubtreeSize = rootIndex - inStart;
        root->left = buildTreeHelper(inorder,inStart,rootIndex - 1,postorder,postStart,postStart + leftSubtreeSize - 1,mp);
        root->right = buildTreeHelper(inorder,rootIndex + 1,inEnd,postorder,postStart + leftSubtreeSize,postEnd - 1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder)
    {
        // inorder  : left -> root -> right
        // postorder: left -> right -> root
        map<int,int> mp;
        for(int i = 0;i < inorder.size();i++)
        {
            mp[inorder[i]] = i;
        }
        TreeNode* root = buildTreeHelper(inorder,0,inorder.size() - 1,postorder,0,postorder.size() - 1,mp);
        return root;
    }
};