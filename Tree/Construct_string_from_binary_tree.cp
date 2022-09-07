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
    void dfs(TreeNode*root , string &s){
        if(root==NULL){
            return ;
        }
        if(root!=NULL){
           s+= to_string(root->val);
        }
        if(root->left!=NULL){
            s.push_back('(');
            dfs(root->left , s);
            s.push_back(')');
        }
        
        if(root->right!=NULL){
            if(root->left==NULL){   //important Base case
                s.push_back('(');                
                s.push_back(')');

            }
              s.push_back('(');
              dfs(root->right , s);
              s.push_back(')');
            
        }
        
        
    }
    string tree2str(TreeNode* root) {
        string s = "";
        dfs(root,s);
        return s ;
    }
};
