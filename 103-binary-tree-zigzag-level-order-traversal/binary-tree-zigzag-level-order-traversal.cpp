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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector <int>> allNodes;
        if(root == NULL)
        {
            return allNodes;
        }
        bool leftToRight = true;
        queue<TreeNode *> currentLevel;
        currentLevel.push(root);
        while(currentLevel.empty() == false)
        {
            int currentLevelSize = currentLevel.size();
            vector <int> currentLevelNodes(currentLevelSize);
            for(int index = 0; index < currentLevelSize; index++)
            {
                TreeNode* node = currentLevel.front();
                currentLevel.pop();
                int indexToPut = leftToRight == true ? index : currentLevelSize - index - 1;
                currentLevelNodes[indexToPut] = node -> val;
                if(node -> left != NULL)
                {
                    currentLevel.push(node -> left);
                }
                if(node -> right != NULL)
                {
                    currentLevel.push(node -> right);
                }

            }
            leftToRight = !leftToRight;
            allNodes.push_back(currentLevelNodes);
        }
        return allNodes;
    }
};













