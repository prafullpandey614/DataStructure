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
    vector<int>digits = vector<int>(10,0);
    int count = 0;
    int k = 10;
    
    void dfs(TreeNode*root){
        if(root==NULL) return ;
        digits[root->val]++;
        if(root->left==NULL && root->right==NULL) {
            if(isPalindrome()){
                count++;
            }
           
        }
        
        else{
            dfs(root->left);
            dfs(root->right);
        }
        digits[root->val]--;
        
    }
    bool isPalindrome(){
        int cnt = 0 ;
        for(int i = 1; i <10;++i){
            if((digits[i])&1) cnt++;
        }
        if(cnt>1) return 0;
        return 1;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        for(int x:digits) x=0;
        count=0;
        dfs(root);
        return count;
    }
};
