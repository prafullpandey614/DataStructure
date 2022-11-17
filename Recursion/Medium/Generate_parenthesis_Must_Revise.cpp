class Solution
{
    public:
    vector<string>ans;
    void generate(string &curr,int left ,int right){
        if(right==0 && left==0){
            ans.push_back(curr);
            return ;
        }
        if(right<0 || left<0) return ;
       
        
        if(left>right) return ;
        if(left==right){
             curr.push_back('(');
             generate(curr,left-1,right);
             curr.pop_back();
        }
        
        else{
             curr.push_back('(');
             generate(curr,left-1,right);
             curr.pop_back();
             curr.push_back(')');
             generate(curr,left,right-1);
             curr.pop_back();
        }
    //   return  ;
        
        
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        string s="";
        ans.clear();
        generate(s,n,n);
        return ans;
        
    }
};
