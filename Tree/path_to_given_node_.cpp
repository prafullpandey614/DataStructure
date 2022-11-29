/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool dfs(TreeNode*root,int b,vector<int>&ans){
     if(!root){
        return 0;
    }
    if(root->val==b){
        ans.push_back(b);
        return 1;
    }
    ans.push_back(root->val);
    bool a = 0;
    if(root->left)
    a|=dfs(root->left,b,ans);
    if(root->right){
        a|=dfs(root->right,b,ans);
    }
    if(a) return a;
    ans.pop_back();
    return a;
   
    
    
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>ans;
    bool k = dfs(A,B,ans);
    // if(!k) return {};
    return ans;
}
