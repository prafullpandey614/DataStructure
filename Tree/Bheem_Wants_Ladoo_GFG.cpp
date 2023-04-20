//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{

    public:
   void after(Node* root, int dist, int &k, int &ans){
        if(root == nullptr || root -> data < 0) return ;
        if(dist <= k){ ans += root -> data; root -> data *= -1; }
        else return;
        
        after(root -> left, dist + 1, k, ans);
        after(root -> right, dist + 1, k, ans);
    }
    
    int dist(Node * root, int &k, int home, int &ans){
        if(root == nullptr) return -1;
        if(root -> data == home){ after(root, 0, k, ans); return 0; }
        
        int left = dist(root -> left, k, home, ans);
        int right = dist(root -> right, k, home, ans);
        
        int cur = -1;
        if(left != -1){
            cur = left + 1;
        }
        else if(right != -1){
            cur = right + 1;
        }
        
        if(cur != -1 and cur <= k){ 
            after(root, cur, k, ans);
        }
        
        return cur;
    }
    
    public:
    int ladoos(Node* root, int home, int k){
        int ans = 0;
        dist(root, k, home, ans);
        return ans;
    }

};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends
