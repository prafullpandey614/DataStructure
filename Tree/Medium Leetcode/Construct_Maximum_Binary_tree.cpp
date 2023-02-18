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
    #define pb push_back 
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0) return NULL ;
        int root = -1;
        int n = nums.size();
        int ind = -1; 
        for(int i = 0 ;i < n ; ++i){
            if(root<nums[i]) root = nums[i],ind = i ; 
        }
        vector<int>left ;
        vector<int>right ;
         for(int i = 0 ; i < ind; ++i){
            left.pb(nums[i]);
        } 
        for(int i = ind+1 ;i < n ; ++i){
            right.pb(nums[i]);
        }
        TreeNode*left_node = constructMaximumBinaryTree(left);
        TreeNode*right_node = constructMaximumBinaryTree(right);
        TreeNode*root_node = new TreeNode(root);
        root_node->left = left_node ;
        root_node->right = right_node ;
        return root_node ;

    }
};
