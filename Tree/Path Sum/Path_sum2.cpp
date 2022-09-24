int t_sum ;
class Solution {
public:
    #define pb push_back
    #define null NULL
    void dfs(TreeNode* root,int curr,vector<int>&dt , vector<vector<int>>&ans){
        if(root){
             dt.pb(root->val);
             curr+=root->val;
        }
        
        if(root->left==null && root->right==null){
          
            if(curr==t_sum){
                // cout<<t_sum<<" "<<curr<<endl;
             ans.pb(dt);
             
                }
            
            dt.pop_back(); 
            curr==0;
            // cout<<t_sum<<endl;
            return ;
            
            
        }
        
        if(root->left){
            
           
            dfs(root->left , curr , dt , ans);
        }
         if(root->right){
           
            dfs(root->right , curr , dt , ans);
        }
        curr-=root->val;
        dt.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        t_sum = targetSum;
        vector<int>dt;
        vector<vector<int>>ans;
        dfs(root,0,dt,ans);
        return ans;
    }
};
