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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> allNodes;
        if(root == NULL)
        {
            return allNodes;
        }
        stack<TreeNode *> inorder;
        // inorder.push(root);
        while(true)
        {
            if(root != NULL)
            {
                inorder.push(root);
                root = root -> left;
            }
            else
            {
                if(inorder.empty() == true)
                {
                    break;
                }
                TreeNode * node = inorder.top();
                inorder.pop();
                allNodes.push_back(node -> val);
                root = node -> right;
            }
        }
        return allNodes;
    }
};