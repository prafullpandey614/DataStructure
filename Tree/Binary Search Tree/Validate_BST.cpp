class Solution {
public:
    bool check(TreeNode*root,long minR,long maxR){
        if(!root) return 1;
        if(root->val > minR && root->val<maxR){
            return check(root->left,minR,root->val) && check(root->right,root->val,maxR);
        }
        return 0;
       
    }
    bool isValidBST(TreeNode* root) {
       
        return check(root,LONG_MIN,LONG_MAX);
    }
};
