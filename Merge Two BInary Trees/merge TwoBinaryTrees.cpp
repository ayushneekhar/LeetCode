#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
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
    void traverse(TreeNode *t1, TreeNode *t2, TreeNode *&mergedTree)
    {
        if (!t1 && !t2)
            return;
        else if (t1 && !t2)
        {
            TreeNode *node(new TreeNode(t1->val));
            mergedTree = node;
            traverse(t1->left, t2, mergedTree->left);
            traverse(t1->right, t2, mergedTree->right);
        }
        else if (!t1 && t2)
        {
            TreeNode *node(new TreeNode(t2->val));
            mergedTree = node;
            traverse(t1, t2->left, mergedTree->left);
            traverse(t1, t2->right, mergedTree->right);
        }
        else if (t1 && t2)
        {
            TreeNode *node(new TreeNode(t1->val + t2->val));
            mergedTree = node;
            traverse(t1->left, t2->left, mergedTree->left);
            traverse(t1->right, t2->right, mergedTree->right);
        }
    }

    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        TreeNode *mergedTree(nullptr);
        traverse(root1, root2, mergedTree);

        // if (!root1 && !root2)
        //     return nullptr;

        // int val1 = root1 ? root1->val : 0; // if root1 is not null then value is assigned, else value = 0;
        // int val2 = root2 ? root2->val : 0;

        // TreeNode *t = new TreeNode(val1 + val2);
        // t->left = mergeTrees(root1 ? root1->left : nullptr, root2 ? root2->left : nullptr);
        // t->right = mergeTrees(root1 ? root1->right : nullptr, root2 ? root2->right : nullptr);
        // return t;

        return mergedTree;
    }
};