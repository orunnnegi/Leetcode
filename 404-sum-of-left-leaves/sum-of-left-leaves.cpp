/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return 0;
        }
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int sum = 0;
        while (!q.empty()) {
            TreeNode* x = q.front().first;
            if (x->left == nullptr && x->right == nullptr &&
                q.front().second == 1) {
                sum += x->val;
            }
            if (x->left != nullptr) {
                q.push({x->left, 1});
            }
            if (x->right != nullptr) {
                q.push({x->right, 0});
            }
            q.pop();
        }
        return sum;
    }
};