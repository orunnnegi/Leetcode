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
    int maxiPath(TreeNode * root , int &maxi)
    {
        if(root == NULL)
        {
            return 0;
        }
        int left = max(0, maxiPath(root -> left , maxi));
        int right = max(0, maxiPath(root -> right , maxi));
        maxi = max(maxi , root -> val + left + right);
        return max(left , right) + root -> val;
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        int solution = maxiPath(root , maxi);
        return maxi;
    }
};