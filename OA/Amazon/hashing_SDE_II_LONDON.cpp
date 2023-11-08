// problem link : https://docs.google.com/document/d/1-TYMJDQNpwvSCXEwv4oRC_xui9Odl4kueMJ4Ue6oXIc/edit


#include <bits/stdc++.h>
using namespace std ;
int lastIndex[26];
int firstIndex[26];
bool check(string &s,int i,int j){
    if(j<i) return false ;
    for(int id = 0 ; id < 26 ; ++id){
        int lft = firstIndex[id];
        int rht = lastIndex[id];
        if((rht<i and lft<i) or (lft>j and rht>j)or (lft>=i and rht<=j) or(lft<i and rht>j)){
            // cout<<"-->"<<lft<<" "<<rht<<" "<<i<<" "<<j<<endl;
        }
        else {
            
            return false;
            
        }
    }
    // cout<<i<<" "<<j<<endl ;
    return 1 ;
}

int solve(string &s){
    for(int i = 0 ; i <26 ; ++i){
        // if(firstIndex[i])
        firstIndex[i] = -1 ; lastIndex[i] = -1; 
    }
     for(int i = 0 ; i <s.size() ; ++i){
        if(firstIndex[s[i]-'a']==-1) {
            firstIndex[s[i]-'a'] = i;
        }
        lastIndex[s[i]-'a'] = i ;
        
    }
    int ans = 0 ;
    for(int i = 0 ; i < 26; ++i){
        int lft = firstIndex[i] ;
        if(lft==-1) continue ;
        for(int j = 0 ; j < 26; ++j){
            int rht = lastIndex[j];
            if(rht==-1) continue ;
            if(rht-lft+1==s.size() or rht<lft) continue ;
            if(check(s,lft,rht)) {
                // cout<<i<<" "<<j<<" "<<lft<<" "<<rht<<" "<<rht-lft+1<<endl ;
                ans = max(ans,rht-lft+1);
            }
            
         }
         
    }
    return ans ;
    
}

int main() {
    // Write C++ code here
    // std::cout << "Hello world!";
    string s;
    cin>>s;
    
    cout<<solve(s)<<endl;
    return 0;
}
