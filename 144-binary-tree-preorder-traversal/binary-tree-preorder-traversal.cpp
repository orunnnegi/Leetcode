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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> allNodes;
        if(root == NULL)
        {
            return allNodes;
        }
        stack<TreeNode *> currentNodes;
        currentNodes.push(root);
        while(currentNodes.empty() == false)
        {
            TreeNode * topNode = currentNodes.top();
            currentNodes.pop();
            if(topNode -> right != NULL)
            {
                currentNodes.push(topNode -> right);
            }
            if(topNode -> left != NULL)
            {
                currentNodes.push(topNode -> left);
            }
            allNodes.push_back(topNode -> val);
        }
        return allNodes;
    }
};