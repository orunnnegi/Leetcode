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
    // map<int, int> mpp;
public:
    unordered_map<int , int> mpp;
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
            inorder(root->left);
            mpp[root->val]++;
            inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        inorder(root);
        int highest= 0;
        for(auto &it : mpp){
            highest= it.second>highest? it.second: highest;
        }
        for(auto it: mpp){
            if(it.second== highest){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};