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
    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        // preorder : root -> left -> right
        if(preorder.empty())
        {
            return nullptr;
        }
        int rootValue = preorder[0];
        TreeNode* root = new TreeNode(rootValue);
        vector<int> leftSubTree;
        vector<int> rightSubTree;
        for(int i = 1; i < preorder.size(); i++)
        {
            if(preorder[i] < rootValue)
            {
                leftSubTree.push_back(preorder[i]);
            }
            else
            {
                rightSubTree.push_back(preorder[i]);
            }
        }
        root->left = bstFromPreorder(leftSubTree);
        root->right = bstFromPreorder(rightSubTree);
        return root;
    }
};