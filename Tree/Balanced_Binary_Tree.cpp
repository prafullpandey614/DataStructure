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
    int height(TreeNode* root){
       if(!root) return 0;
        
       int h1=0,h2=0;
       if(root->left){
           h1 = 1+ height(root->left);
       }
       if(root->right){
           h2 = 1+ height(root->right);
       }
      
       if(abs(h2-h1)>1) return -1;
       if(h1==-1 || h2==-1) return -1;
           return max(h1,h2);
    }
    bool isBalanced(TreeNode* root) {
       int a=0,b=0;
        if(!root) return 1;
        if(root->left){
            a = 1+height(root->left);
         }
        if(root->right){
            b = 1+height(root->right);
        }
        if(abs(a-b)<=1 && isBalanced(root->right) && isBalanced(root->left))
        return 1;
        return  0;
    }
};
