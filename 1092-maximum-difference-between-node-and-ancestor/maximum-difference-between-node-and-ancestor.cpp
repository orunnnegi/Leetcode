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
    // time/space: O(n)/O(h)
    int maxAncestorDiff(TreeNode* root, int maxValue=-1e9, int minValue=1e9) {
        // terminate
        if (root == NULL) return (maxValue - minValue);

        // update the maximum and minimum values
        maxValue = max(maxValue, root->val);
        minValue = min(minValue, root->val);

        // enumerate
        return max(
            maxAncestorDiff(root->left, maxValue, minValue),
            maxAncestorDiff(root->right, maxValue, minValue)
        );
    }
};