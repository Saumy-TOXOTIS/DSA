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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        // map<col, map<level, multiset<val>>>
        // This structure automatically handles all sorting requirements.
        map<int, map<int, multiset<int>>> nodes;

        // Queue for BFS traversal: {node, {column, level}}
        queue<pair<TreeNode*, pair<int, int>>> todo;

        if (root) {
            todo.push({root, {0, 0}});
        }

        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();

            TreeNode* node = p.first;
            int col = p.second.first;
            int level = p.second.second;

            // Insert the node's value into our ordered data structure.
            nodes[col][level].insert(node->val);

            if (node->left) {
                todo.push({node->left, {col - 1, level + 1}});
            }
            if (node->right) {
                todo.push({node->right, {col + 1, level + 1}});
            }
        }

        // Format the final output. No sorting is needed here.
        vector<vector<int>> ans;
        for (auto const& [col, level_map] : nodes) {
            vector<int> col_vals;
            for (auto const& [level, val_set] : level_map) {
                col_vals.insert(col_vals.end(), val_set.begin(), val_set.end());
            }
            ans.push_back(col_vals);
        }

        return ans;
    }
};