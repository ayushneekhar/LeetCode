#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    // Helper function to find the right most node of the sub tree.
    TreeNode *right_most_helper(TreeNode *root)
    {
        if (!root->right)
            return root;
        return right_most_helper(root->right);
    }

public:
    void flatten(TreeNode *root)
    {
        if (!root)
            return;

        TreeNode *right_most; // Variable to store the right most node, this is where we eill reconnect the right
                              // subtree after we disconnect it from the node.

        TreeNode *right_subtree; // Variable to store the right subtree of a node, as we will disconnect it and connect
                                 // the left subtree in this place, using this variable we'll be able to reconnect the
                                 // disconnected right subtree.

        while (root)
        {
            if (root->left)
            {                                               // If there is a left subtree, then we need to flatten it.
                right_most = right_most_helper(root->left); // Find the right most node and inser (ronnection point)
                right_subtree = root->right;                // Store the right subtree before disconnecting it
                root->right = root->left;                   // Connect the left subtree of a node to its right side
                                                            // flattening the tree.
                root->left = NULL;                          // Make the left subtree of the root to NULL
                right_most->right = right_subtree;          // Reconnect the right subtree we disconnected earlier to the
                                                            // rightmost point of the left subtree (which is now connected
                                                            // to the right side of the node)
            }

            root = root->right;
        }
    }
};