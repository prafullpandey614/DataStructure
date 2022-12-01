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
    TreeNode*build(vector<int>& preorder,int prestart,int prend ,vector<int>& inorder,int instart,int inend,unordered_map<int,int>&inmap){
        if(prestart>prend || instart>inend) return NULL ;
        TreeNode*root = new TreeNode(preorder[prestart]);
        int inRoot = inmap[root->val];
        int numsLeft = inRoot - instart ;
        TreeNode*lef = build(preorder,prestart+1,prestart+numsLeft,inorder,instart,inRoot-1,inmap);
        TreeNode*righ = build(preorder,prestart+numsLeft+1,prend,inorder,inRoot+1,inend,inmap);
        root->left = lef ;
        root->right = righ ;
        return root ;
        
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i = 0; i<inorder.size();++i) {
            mp[inorder[i]] = i;
        }
        TreeNode*root = build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root ;
    }
};
