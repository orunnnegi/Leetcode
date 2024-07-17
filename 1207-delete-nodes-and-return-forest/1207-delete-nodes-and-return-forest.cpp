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
    vector<TreeNode*> result;
    set<int> to_delete_set;

    TreeNode* helper(TreeNode* node, bool is_root) {
        if (node == nullptr) {
            return nullptr;
        }

        bool deleted = to_delete_set.find(node->val) != to_delete_set.end();

        if (is_root && !deleted) {
            result.push_back(node);
        }

        node->left = helper(node->left, deleted);
        node->right = helper(node->right, deleted);

        return deleted ? nullptr : node;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int i : to_delete) {
            to_delete_set.insert(i);
        }

        helper(root, true);

        return result;
    }    
};