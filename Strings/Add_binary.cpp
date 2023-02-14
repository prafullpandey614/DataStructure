class Solution {
public:
    string addBinary(string a, string b) {
        int al = a.length();

        int bl = b.length();
        string output = "";
        int n = max(al,bl);
        string temp = "";
        for(int i = 0 ; i < abs(al-bl); ++i){
            temp.push_back('0');
        }
        if(al>bl){
            b=temp+b ;

        }
        else a= temp+a; 
        

       
        int carry = 0 ;
        for(int i = n-1; i>=0; --i){
            if(a[i]=='1' && b[i]=='1'){
                if(carry==1){
                    output.push_back('1');

                }
                else {
                    output.push_back('0');
                   
                }
                 carry = 1 ;
            }
            else if((a[i]=='1' and b[i]=='0') or (a[i]=='0' and b[i]=='1')){
                if(carry){
                  
                    output.push_back('0');
                    carry = 1;
                        
                  
                }
                  else output.push_back('1'),carry = 0;
             
                
            }
               else{
                     if(carry){
                        output.push_back('1');
                      
                        }
                        else output.push_back('0');
                        carry = 0; 
                }
        }
        if(carry) output+='1';
        reverse(output.begin(),output.end());
        return output ;
    }
};
