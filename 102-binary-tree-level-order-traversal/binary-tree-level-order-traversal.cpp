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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> allNodes;
        if(root == NULL)
        {
            return allNodes;
        }
        queue<TreeNode *> nodesAtLevel;
        nodesAtLevel.push(root);
        while(nodesAtLevel.empty() == false)
        {
            int size = nodesAtLevel.size();
            vector<int> nodesAtCurrLevel;
            for(int index = 0; index < size; index++)
            {
                TreeNode * currNode = nodesAtLevel.front();
                nodesAtLevel.pop();
                if(currNode -> left != NULL)
                {
                    nodesAtLevel.push(currNode -> left);
                }
                if(currNode -> right != NULL)
                {
                    nodesAtLevel.push(currNode -> right);
                }
                nodesAtCurrLevel.push_back(currNode -> val);
            }
            
            allNodes.push_back(nodesAtCurrLevel);
        }
        return allNodes;
    }
};