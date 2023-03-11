class Solution {
public:
    int ans(int n,int k){
        if(n==1 ){
            return 0;
        }
        int mid = (1<<(n-1))/2;
        if(k<=mid){
            return ans(n-1,k);
        }
        else return 1-ans(n-1,k-mid);
        
    }
    int kthGrammar(int n, int k) {
        return ans(n,k);
    }
};

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) return 0;
        int mid = ((1<<(n-1)))>>1 ;
        if(k<=mid){
            return kthGrammar(n-1,k);
        }
        else{
            return 1-kthGrammar(n-1,k-mid); //toggling the result and making k inside mid , rest is same 
        }

    }
};
