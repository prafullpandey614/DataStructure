class Solution {
    public int minSizeSubarray(int[] nums, int target) {
        long[] pref = new long[nums.length+1];
        long[] suff = new long[nums.length+1];
        HashMap<Long,Long>hmp = new HashMap<>();        
        HashMap<Long,Long>bmp = new HashMap<>();

        Arrays.fill(pref,0);       
        Arrays.fill(suff,0);
        long sum = 0 ;long ans = 100000000;
        for(int i = 0 ; i< nums.length ; ++i){
            pref[i+1] = pref[i]+nums[i];
            if(hmp.containsKey(pref[i+1]-target)){
                System.out.println("Iam here");
                ans = Math.min(ans,i+1 - hmp.get(pref[i+1]-target));
            }
            else if(pref[i+1]==target){
                ans = Math.min(ans,i+1);
            }
            hmp.put(pref[i+1],(long)i+1);
            sum+=nums[i] ;
        }
         for(int i = nums.length-1  ; i>=0 ; --i){
           suff[i] = suff[i+1]+nums[i];
            bmp.put(suff[i],(long)i+1); 
        }
        
        
            
        for(int i = 0 ; i<nums.length ; ++i){
            long req =  target - pref[i+1] ;
            long  rem = req %sum ;
            long k = req/sum ;



            if(bmp.containsKey(rem)){
                ans = Math.min(ans,nums.length-(long)bmp.get(rem)+1+hmp.get(pref[i+1])+((nums.length)*k));
            }
            else if (rem==0){
                ans = Math.min(ans,k*nums.length+hmp.get(pref[i+1]));
            }
        }
        if(ans==100000000) return -1;
        return (int)ans ;
 
        
    }
}
