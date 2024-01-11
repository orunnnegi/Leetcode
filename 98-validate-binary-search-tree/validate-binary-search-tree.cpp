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

    bool helper(TreeNode *root, long long minRange , long long maxRange)
    {
        if(root == NULL)
        {
            return true;
        }
        if(root -> val >= maxRange or root -> val <= minRange)
        {
            return false;
        }
        return helper(root -> left , minRange , root -> val) and helper(root -> right, root -> val, maxRange);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root , LLONG_MIN, LLONG_MAX);
    }
};