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
    int ans=0;
    void check(vector<int>&store){
        int freq=0;
        for(int i=1; i<10 ;i++){
            if(store[i]%2!=0){
                freq++;
            }
        }
        if(freq<=1){
            ans++;
        }

    }
    void solve(TreeNode*root , int temp){
        if(root==NULL){
            return;
        }
       
        temp = (temp ^ (1<<root->val));
               
        if(root->left==NULL && root->right==NULL){

           if((temp&(temp-1))==0){
               ans++;
           }
        }
        
        solve(root->left , temp);
        solve(root->right,temp);

    }  
    int pseudoPalindromicPaths (TreeNode* root) {
        int temp=0;
        solve(root, temp);
        return ans;
    }
};