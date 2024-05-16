class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (root->val <= 1)
            return root->val;
        else if (root->val == 2)
            return evaluateTree(root->left) || evaluateTree(root->right);
        else
            return evaluateTree(root->left) && evaluateTree(root->right);
    }
};