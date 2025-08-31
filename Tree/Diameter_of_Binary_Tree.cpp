#include <bits/stdc++.h>
using namespace std;

//Diameter -> Longest path between any two node

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
    int diameter = 0;
    int recursion(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int left = recursion(root->left);
        int right = recursion(root->right);
        diameter = max(diameter,left + right);
        return (1 + max(left,right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        recursion(root);
        return diameter;
    }
};