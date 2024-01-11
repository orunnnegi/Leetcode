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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        if( root == NULL )
        {
            return rightView;
        }
        queue<pair<TreeNode *, int>> levelTraversal;
        map<int , int> allNodes;
        levelTraversal.push({root , 0});
        while(levelTraversal.empty() == false)
        {
            auto node = levelTraversal.front();
            levelTraversal.pop();
            TreeNode * currentNode = node.first;
            int level = node.second;
            allNodes[level] = currentNode -> val;
            if(currentNode -> left != NULL)
            {
                levelTraversal.push({currentNode -> left , level + 1});
            }
            if(currentNode -> right != NULL)
            {
                levelTraversal.push({currentNode -> right , level + 1});
            }
        }
        for( auto node : allNodes )
        {
            rightView.push_back(node.second);
        }
        return rightView;
    }
};