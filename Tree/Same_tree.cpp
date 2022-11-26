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
    bool trav(TreeNode*p,TreeNode*q){
        if(!p && q) return 0;
        if(!q && p) return 0;
        if(!p && !q) return 1 ;
        if(p->val!=q->val){
            return 0;
        }
        bool a =0,b=0;A
        a = trav(p->left,q->left);
        b = trav(p->right,q->right);
        return a&b ;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return trav(p,q);
    }
};
