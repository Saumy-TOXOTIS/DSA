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

vector<int> topView(TreeNode *root)
{
    if(!root)
    {
        return {};
    }
    map<int,int> mp;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        auto item = q.front();
        q.pop();
        TreeNode* node = item.first;
        int line = item.second;
        if(mp.find(line) == mp.end())
        {
            mp[line] = node->val;
        }
        if(node->left)
        {
            q.push({node->left,line - 1});
        }
        if(node->right)
        {
            q.push({node->right,line + 1});
        }
    }
    vector<int> ans;
    for(auto item : mp)
    {
        ans.push_back(item.second);
    }
    return ans;
}