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

/*
width -> maximum number of nodes at any level in the binary tree.
*/

class Solution
{
public:
    int widthOfBinaryTree(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        int ans = 0;
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root, 0});
        while(!q.empty())
        {
            int size = q.size();
            unsigned long long minIdx = q.front().second;
            unsigned long long first;
            unsigned long long last;
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = q.front().first;
                unsigned long long index = q.front().second - minIdx;
                q.pop();
                if(i == 0)
                {
                    first = index;
                }
                if(i == size - 1)
                {
                    last = index;
                }
                if(node->left)
                {
                    q.push({node->left,2*index + 1});
                }
                if(node->right)
                {
                    q.push({node->right,2*index + 2});
                }
            }
            ans = max(ans,(int)(last - first + 1));
        }
        return ans;
    }
};