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
bool check=0,ans=0;
int t_sum = 0;
class Solution {
public:
    void dfs(TreeNode* root ,int curr ){
        
        if(root) curr+=root->val;
        if(root->left==NULL && root->right==NULL){
        if(curr==t_sum ){
            check  = 1;
            return ;
        }
            
        }
        if(root->left) dfs(root->left,curr);
        if(root->right) dfs(root->right,curr);
        curr-=root->val;
        
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        check = 0;
        if(!root) return {};
         t_sum = targetSum;
        dfs(root,0);
        if(check) return 1;
        return 0;
        
    }
};
