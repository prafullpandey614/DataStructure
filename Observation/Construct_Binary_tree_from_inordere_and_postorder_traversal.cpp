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
    TreeNode*create(vector<int>&postorder,int stpost,int endpost,vector<int>&inorder,int stin,int endin,unordered_map<int,int>&mp){
  
        if(stpost>endpost || stin>endin) return NULL;
        int inRoot = mp[postorder[endpost]];
        int numsRight = endin-inRoot;
        TreeNode*root = new TreeNode(postorder[endpost]);
        root->right = create(postorder,endpost-numsRight,endpost-1,inorder,inRoot+1,endin,mp);
        root->left  = create(postorder,stpost,endpost-numsRight-1,inorder,stin,inRoot-1,mp);
        return root ;
        
        
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        for(int i = 0 ; i < inorder.size() ; ++i){
            mp[inorder[i]]=i;
        }
        
        TreeNode*root= create(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root ;
    }
};
