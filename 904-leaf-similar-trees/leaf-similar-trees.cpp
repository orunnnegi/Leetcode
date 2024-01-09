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
    void collectLeaves(TreeNode *root , vector<int> &v)
    {
        if( root == NULL )
        {
            return;
        }
        if(root -> left == NULL and root -> right == NULL)
        {
            v.push_back(root -> val);
        }
        if(root -> left != NULL)
        {
            collectLeaves(root -> left, v);
        }
        if(root -> right != NULL)
        {
            collectLeaves(root -> right, v);
        }


    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leavesTreeOne;
        vector<int> leavesTreeTwo;
        collectLeaves(root1, leavesTreeOne);
        collectLeaves(root2, leavesTreeTwo);
        return leavesTreeOne == leavesTreeTwo;   
    }
};