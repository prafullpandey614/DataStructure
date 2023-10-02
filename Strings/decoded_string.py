class Solution:
    def decodeAtIndex(self, s: str, k: int) -> str:
        decoded_string = ""
        for c in s:
            if c.isdigit():
                temp = decoded_string 
                j = 1 
                c = int(c)
                # while j<c:a
                #     decoded_string += temp
                #     j+=1
            else :
                decoded_string += c
        return decoded_string
