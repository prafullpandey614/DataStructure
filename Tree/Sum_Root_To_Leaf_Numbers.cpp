class Solution {
public:
    int dfs(TreeNode*root,int num){
        if(!root) return  0;
        if(root->left==NULL && !root->right){
            return num*10+root->val;
        }
        num = num*10+root->val ;
        return dfs(root->left,num)+dfs(root->right,num);
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
};
