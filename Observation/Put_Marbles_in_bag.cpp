class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        drr = []
        for i in range(len(weights)-1):
            drr.append(weights[i]+weights[i+1])
        drr.sort()
        maxiwala = 1000000007
        miniwala = 1000000007
        sum1 = 0 
        sum2 = 0
        for i in range(k-1):
            sum1+=drr[len(drr)-i-1]
            sum2+=drr[i]
        return sum1-sum2
        
