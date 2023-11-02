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
    int ans = 0;

    pair<int,int> postorder(TreeNode* &root,int sum,int count)
    {
        if(root == 0) return {0,0};

        auto l = postorder(root->left,sum,count);
        auto r = postorder(root->right,sum,count);

        sum = l.first + root->val + r.first;
        count = l.second + 1 + r.second;

        if(sum / count == root->val) ans++;
        return {sum,count};
    }

    int averageOfSubtree(TreeNode* root) {
        postorder(root,0,0);
        return ans;
    }
};