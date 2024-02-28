class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (!root) {
            return 0; // or any default value based on the problem constraints
        }

        int leftmostValue = 0;
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            leftmostValue = q.front()->val;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* current = q.front();
                q.pop();

                if (current->left) {
                    q.push(current->left);
                }

                if (current->right) {
                    q.push(current->right);
                }
            }
        }

        return leftmostValue;
    }
};