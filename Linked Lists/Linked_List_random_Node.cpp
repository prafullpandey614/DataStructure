# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    lt = []
    def __init__(self, head: Optional[ListNode]):
        self.lt=  []
        while head!= None:
            self.lt.append(head.val)
            head = head.next

    def getRandom(self) -> int:
        return random.choice(self.lt)


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()
