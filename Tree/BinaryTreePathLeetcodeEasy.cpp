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
    void dfs(TreeNode*node , string s,vector<string>&ans){
        if(node->right==NULL && node->left==NULL){
            
            ans.push_back(s);
            return ;
        }
        
        if(node->left){
            dfs(node->left,s+"->"+ to_string(node->left->val),ans);
        }
        if(node->right){
            dfs(node->right,s+"->"+to_string(node->right->val),ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(!root) return ans;
        string s = to_string(root->val);
        
        dfs(root,s,ans);
        return ans ;
    }
};
