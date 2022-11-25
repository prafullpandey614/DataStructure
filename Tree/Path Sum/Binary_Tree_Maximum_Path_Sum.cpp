//this question is based on height & diameter of binary tree concept so remeber those concepts to solve these types of problems
class Solution {
public:
    int maxP(TreeNode*node,int &sum){
        if(!node) return 0;
        
        int leftsum  = maxP(node->left,sum); 
        int rightsum = maxP(node->right,sum); 
        sum = max(sum,leftsum+rightsum+node->val);  
        if(node->val+max(leftsum,rightsum)>0)
        return node->val+max(leftsum,rightsum); 
        return 0;
    }
    int maxPathSum(TreeNode* root) {
        int PathSum = INT_MIN;
        maxP(root,PathSum);
        return PathSum; 
    }
};
