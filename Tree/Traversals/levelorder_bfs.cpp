  vector<int> levelOrder(Node* node)
    {
      queue<Node*>q;
      q.push(node);
      vector<int>ans;
      while(!q.empty()){
          int k = q.size();
          
          for(int i= 0 ; i < k ; ++i){
              ans.push_back(q.front()->data);
              
              if(q.front()->left) q.push(q.front()->left);
              if(q.front()->right) q.push(q.front()->right);
              q.pop();
          }
      }
      return ans;
    }
