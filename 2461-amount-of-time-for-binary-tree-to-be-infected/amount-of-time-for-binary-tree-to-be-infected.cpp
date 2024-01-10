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
class Solution
{
    int ans = 0;
    int traverse(int start, TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int leftdepth = traverse(start, root->left);
        int rightdepth = traverse(start, root->right);

        int depth = 0;
        if (root->val == start)
        {
            ans = max(leftdepth, rightdepth);
            depth = -1;
        }
        else if (leftdepth >= 0 && rightdepth >= 0)
        {
            depth = max(leftdepth, rightdepth) + 1;
        }
        else
        {
            int dist = abs(leftdepth) + abs(rightdepth);
            ans = max(ans, dist);
            depth = min(leftdepth, rightdepth) - 1;
        }
        return depth;
    }

public:
 Solution(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
    int amountOfTime(TreeNode *root, int start)
    {
        traverse(start, root);
        return ans;
    }
};