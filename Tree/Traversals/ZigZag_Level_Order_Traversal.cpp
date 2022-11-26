class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       
//         vector < vector < int >> result;
//   if (root == NULL) {
//     return result;
//   }

//   queue < TreeNode * > nodesQueue;
//   nodesQueue.push(root);
//   bool leftToRight = true;

//   while (!nodesQueue.empty()) {
//     int size = nodesQueue.size();
//     vector < int > row(size);
//     for (int i = 0; i < size; i++) {
//       TreeNode * node = nodesQueue.front();
//       nodesQueue.pop();

//       // find position to fill node's value
//       int index = (leftToRight) ? i : (size - 1 - i);

//       row[index] = node -> val;
//       if (node -> left) {
//         nodesQueue.push(node -> left);
//       }
//       if (node -> right) {
//         nodesQueue.push(node -> right);
//       }
//     }
//     // after this level
//     leftToRight = !leftToRight;
//     result.push_back(row);
//   }
//   return result;
        
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        bool flag= 0;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int>a;
            for(int i = 0 ; i < sz ; ++i){
                TreeNode*temp  = q.front();
                q.pop();
                a.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                
            }
            if(flag){
                reverse(a.begin(),a.end());
            }
            flag = !flag ;
            ans.push_back(a);
        }
        return ans ;
    }
};
