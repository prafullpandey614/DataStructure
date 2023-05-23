class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        pref = []
        pref.append(0)
        for i in range(len(nums)):
            pref.append(pref[i] + nums[i])
        st = 0 
        end = 1
        ans = 10000000
        while end<=len(nums):
            if pref[end]-pref[st]>=target:
                while st<=end and pref[end]-pref[st]>=target:
                    ans = min(ans,end-st)
                    st+=1
            else :
                end+=1
        if ans==10000000:
            return 0
        return ans 
