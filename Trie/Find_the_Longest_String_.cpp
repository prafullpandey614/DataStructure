
#include <bits/stdc++.h> 

struct Node{
  
    Node*links[26];
    bool isEnd = false ;
    
    bool isContainKey(char ch){
      return (links[ch-'a']!=NULL);
        
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void put(char ch,Node* node){
        links[ch-'a'] = node ;
    }
    void setEnd(){
        isEnd = true ;
    }
};

class Trie{
    private  : Node *root ;
    public:
    Trie(){
        root = new Node();
    }
    
    void insert(string word){
    Node* node = root ;
    for(int i = 0; i  <word.size() ;++i){
        if(!node->isContainKey(word[i])){
            node->put(word[i],new Node());
        }
        node = node->get(word[i]);
    }
    node->setEnd();
    }
    
    bool allPrefExist(string s){
        Node*node = root ;
        bool flag = true ;
        for(int i = 0 ;i < s.size() ;++i){
         if(node->isContainKey(s[i])){
             node = node->get(s[i]);
             flag = flag & node->isEnd ;
         }
            else return false;
        }
        return flag;
    }
};

