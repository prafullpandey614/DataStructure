class Solution {
public:
    int ans ;
    void dfs(TreeNode*root,int k ,int &cnt){
       if(!root) return ;
        
        if(root->left){
           
            dfs(root->left,k,cnt);
        }
        cnt++;
        if(cnt==k) {
            ans = root->val;
            return ;
        }
        if(root->right){
            dfs(root->right,k,cnt);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
       int c = 0;
        dfs(root,k,c);
        return ans;
       
    }
};
