struct Node{
    Node*links[26];
    bool flag = 0;
    
    
    bool iscontainskey(char c){
        return links[c-'a']!=NULL;
        
    }
    
    void put(char ch,Node*node){
        links[ch-'a'] = node;
    }
    Node*get(char ch){
        return links[ch-'a'];
    }
    
};
class Trie{
    private:
    Node*root;
    public:
    Trie(){
        root = new Node();
    }
    
    void insert(string word){
        Node*node = root;
        for(int i= 0 ;i < word.size() ;++i){
            if(!node->iscontainskey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->flag=1;
        
    }
    
    //this function will return all the strings starting with This Prefix
    void stringsWithPrefix(string &prefix,vector<string>&ans){
        
        Node*node = root;
        for(char c:prefix){
            if(!node->iscontainskey(c)){
                return ;
            }
            node = node->get(c);
        }
        //now for taking all the 3 strings lexographically we are doing a dfs traversal
        dfs(node,prefix,ans);
        
    }
    
    //this dfs function will help us to find the lexographically at most three strings
    void dfs(Node*curr,string &prefix,vector<string>&ans){
        
        if(ans.size()==3){
            return ;
        }
        
        if(curr->flag) {
            ans.push_back(prefix);
            
        }
        //this for loop is basically to pick up smallest character string 
        for(char ch='a' ; ch<='z' ;++ch){
            if(curr->iscontainskey(ch)){
                prefix.push_back(ch);
                dfs(curr->get(ch),prefix,ans);
                prefix.pop_back(); //backtracking 
            }
        }
        
    }
    
};

class Solution {
public:
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        string prefix = "";
        
        Trie*trie = new Trie();
        for(auto &x:products){
            trie->insert(x);
        }
        
        vector<string>res;
          vector<vector<string>> ans;
        for(char ch:searchWord){
            res.clear();
            prefix.push_back(ch);
            trie->stringsWithPrefix(prefix,res);
            ans.push_back(res);
        }
        return ans;
    }
};
