class Solution {
public:
    bool checkZeroOnes(string s) {
        int onct=0,zct=0;
        int maxo=-1,maxz=-1;
        for(char c:s){
            if(c=='1') {onct++; zct=0;}
            if(c=='0') {zct++; onct=0;}
            
            maxo = max(maxo,onct);
            maxz = max(maxz,zct);
            
        }
        return maxz<maxo;
    }
};
