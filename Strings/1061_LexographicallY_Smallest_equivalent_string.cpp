class Solution {
public:
    int mapping[36];
    int root(int x){
        while(x != mapping[x]){
            x = mapping[x];
        }
        return x;
    }

    void unionn(int a, int b){
        int roota = root(a);
        int rootb = root(b);
        if(roota < rootb){
            mapping[rootb] = roota;
        }
        else{
            mapping[roota] = rootb;
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(int i = 0; i<36; i++){
            mapping[i] = i;
        }

        for(int i=0;i<s1.size(); i++){
            unionn(int(s1[i])-97, int(s2[i])-97);
        }
        for(int i=0; i<baseStr.size(); i++){
            baseStr[i] = char(root(int(baseStr[i]) - 97) + 97);
        }
        return baseStr;
        
    }
};
