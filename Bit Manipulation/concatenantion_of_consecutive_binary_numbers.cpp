class Solution {
public:
    int m = 1e9+7;
    int concatenatedBinary(int n) {
        // if(n == 1) return 1;
        // long long prev = 1;
        // long long bits = 1;
        // for(int i = 2; i <= n; i ++) {
        //     if((i & (i - 1)) == 0) {
        //         bits ++;
        //     }
        //     prev <<= bits;
        //     prev = prev + i;
        //     prev %= ((int)1e9 + 7);
        // } 
        // return (int) prev;
        long long ans=0;
        int i =1;
     while(i<=n){
            
            ans = (((ans << (1+int(log2(i)))%m) + i)%m );    
                   i++;
        }
                   return ans;
    }
};
