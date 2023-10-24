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
    // store maximum at each level in map

    map<int,int> m;

    void helper(TreeNode* root,int l){
        if(!root)return;
        if(m.find(l)==m.end())m[l]=root->val;
        else m[l]=max(m[l],root->val);
        helper(root->left,l+1);
        helper(root->right,l+1);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        helper(root,0);
        for(auto i:m)ans.push_back(i.second);
        return ans;
    }
};