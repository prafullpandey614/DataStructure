class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(p->val>root->val && q->val<root->val){
            return root;
        }
        if(q->val >root->val && p->val<root->val){
           return  root ;
        }
        
        if(p->val==root->val || q->val==root->val){
            return root ;
        }
        
        if(p->val>root->val && q->val>root->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        else return lowestCommonAncestor(root->left,p,q);
        
    }
};
