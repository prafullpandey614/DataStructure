 vector<int> postOrder(Node* node) {
   
        stack<Node*>st1,st2;
        st1.push(node);
        Node * temp ;
        vector<int>ans;
        while(st1.size()){
            temp = st1.top();
            st1.pop();
            if(temp->left){
                st1.push(temp->left);
            }
            if(temp->right) st1.push(temp->right);
            
            st2.push(temp);
            
        }
       while(!st2.empty()) {
           ans.push_back(st2.top()->data);
           st2.pop();
       }
    
        return ans ;
    }
