class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        //Solve it by two pointers
        int n = tokens.size();
        int ans =0;int score=0; 
        int i=0,j = tokens.size()-1;
        while(i<=j){
            if(power >= tokens[i] ){
                score +=  1;
                if(ans<score){
                 ans = score;
                }
                power -= tokens[i];
                i++;
            }
            else if(score>0){
                power += tokens[j];
                score -= 1;
                j--;
            }
            else break;
        }
        return ans;
    }
};
