#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//DFS - Depth First Search

//DFS inorder traversal (left -> root -> right)
void inorder(struct Node *root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//DFS preorder traversal (root -> left -> right)
void preorder(struct Node *root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//DFS postorder traversal (left -> right -> root)
void postorder(struct Node *root)
{
    if(root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

//Level Order or BFS - Breadth First Search
vector<vector<int>> levelNodes;
void levelOrder(struct Node *root)
{
    levelNodes.clear();
    queue<struct Node *> q;
    if(root == NULL)
    {
        return;
    }
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        vector<int> level;
        for(int i = 0;i < n;i++)
        {
            struct Node *node = q.front();
            q.pop();
            if(node->left != NULL)
            {
                q.push(node->left);
            }
            if(node->right != NULL)
            {
                q.push(node->right);
            }
            level.push_back(node->data);
        }
        levelNodes.push_back(level);
    }
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
}