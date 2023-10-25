int isFeasible(unordered_map<int, int> &freq, int groupSize){  
    int totalGroups = 0, highGroupSize = groupSize + 1;                //consider a highGroup with size 1 more than the groupSize we are looking for.
    for(auto [key, fq]:freq){
        int groupCount = fq / highGroupSize, remainder = fq % highGroupSize;          //First try to divide as per highGroupSize
        if(remainder > 0 && remainder < groupSize) {                 //High group size division possible if reminder is zero or reminder is equal to groupSize
            int requiredItem = groupSize - remainder;                //If not possible with higher group size only, then need to find the no of highGroupSize is to be converted to normal groupSize 
            if(groupCount < requiredItem) { return 0; }   //if required group count is not possible at highGroup size count then its not possble at all to divide with groupSize & highGropuSize items
            groupCount = (groupCount - requiredItem) + (remainder + highGroupSize * requiredItem) / groupSize;  // if possible then the new group count is equal to : HighGroupSize count + Normal groupSizeCount, where
                                                                        //HighGroupSize count = groupCount - requiredItem
                                                                        //Normal groupSizeCount = (remainder + highGroupSize * requiredItem) / groupSize
            remainder = 0;                                           //set remainder to zero as we don't needed this valure later
        }
        totalGroups += groupCount + (remainder?1:0);                 //Keep adding the total group count
    }
    return totalGroups;
}

int minGroupsForValidAssignment(vector<int>& nums) {
    unordered_map<int, int> freq;
    int mn = INT_MAX, ans = nums.size();           // initialise the ans with the trivial (max possible groups - each item is one group)
    for(auto n: nums) { freq[n]++; }               // find the frequency of each type item
    for(auto [k,v]:freq) { mn = min(mn, v); }      // find the smallest frequency
    for(int groupSize = mn; groupSize >= 1; --groupSize){  // iterate over the group size from largest possible to smallest 
        int res = isFeasible(freq, groupSize);     // check if the group size is feasible or not - if zero then not feasible 
        if(res) return res;                        // if non zero then the group size is feasible and return it as answer.
    }
    return ans;   
}
