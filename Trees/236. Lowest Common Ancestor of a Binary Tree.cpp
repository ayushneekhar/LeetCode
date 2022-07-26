#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Simple DFS exhaustive search

class Solution
{
    TreeNode *dfs(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return NULL;

        if (root == p or root == q)
            return root; // If we find either of the nodes then we return the node where our value
                         // is found

        TreeNode *left = dfs(root->left, p, q); // Once one of the value is returned we search in the opposite brance of
                                                // the tree, i.e, say we find the value 5, 1st node to the left of 3,
                                                // we will then search to the right of 3, this is because, if we find
                                                // find the value in the right side we know that 3 is the LCA, but if we
                                                // dont find it in the right side that means the value is definitely
                                                // in the left side, meaning the LCA is node 5.
        TreeNode *right = dfs(root->right, p, q);

        if (left and right)
            return root; // If we find the values in both the left and the right side, we return
                         // the root of the left and right brances split

        if (!left and !right)
            return NULL; // If values are not found the values dont exist

        return left != NULL ? left : right; // If only one of the left or right is not NULL then that means both the
                                            // values exist on and below the not NULL node
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return dfs(root, p, q);
    }
};