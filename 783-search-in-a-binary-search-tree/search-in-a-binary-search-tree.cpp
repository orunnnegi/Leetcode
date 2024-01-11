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

    TreeNode* inorderTraversal(TreeNode * root , int element)
    {
        if(root == NULL)
        {
            return NULL;
        }
        if(root -> val == element)
        {
            return root;
        }
        if(root -> val > element)
        {
            return inorderTraversal(root -> left, element);
        }
        if(root -> val < element)
        {
            return inorderTraversal(root -> right, element);
        }
        return NULL;


    }

    TreeNode* searchBST(TreeNode* root, int val) {
        return inorderTraversal(root, val);
    }
};