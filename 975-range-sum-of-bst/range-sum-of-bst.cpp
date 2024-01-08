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
class Solution {
public:

    void inorderTraversal(TreeNode * root, int low, int high, int &requiredSum)
    {
        if(root == NULL)
        {
            return;
        }
        else
        {
            inorderTraversal(root -> left, low, high, requiredSum);
            if((root -> val >= low) and (root -> val <= high))
            {
                requiredSum+= root->val;
            }
            inorderTraversal(root -> right, low, high, requiredSum);
        }
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int requiredSum = 0;
        inorderTraversal(root , low , high, requiredSum);
        return requiredSum;
    }
};