class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        k = 0
        j = 0;
        if needle in haystack:
            for i in range(len(haystack)):
                k = 0
                if(haystack[i]==needle[k]):
                    j = i;
                    while(needle[k]==haystack[i]):
                        k+=1
                        i+=1
                        if k==len(needle) or i==len(haystack):
                            break
                    if k==len(needle):
                        return j;
                    
                    print(i)
                    i = j
                    print(i)
                        
                        
        else :
            return -1
        
