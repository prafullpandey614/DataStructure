class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        if(flowerbed.size() == 1 && flowerbed[0] == 0 && n==1){
            return true;
        }

        if(n==0){
            return true;
        }
        int count = 0;int end = flowerbed.size();
        //for first and last index check like edge cases
        if(flowerbed[0]==0 and flowerbed[1]==0){
           flowerbed[0]=1;
            n-=1;
        }
         if(flowerbed[end-1]==0 and flowerbed[end-2]==0){
           flowerbed[end-1]=1;
            n-=1;
        }
        //
        for(int i = 1; i<flowerbed.size()-1; i++){

            if(flowerbed[i] == 0){

                
                
                    if(flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                        n-=1;
                        flowerbed[i] = 1;
                    }
                
            }
        }

        return n<=0;
    }

};
