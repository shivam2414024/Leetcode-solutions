# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        t1 = headA
        t2 = headB
        while t1 != t2:
            if t1 is None:
                t1 = headB
            else:
                t1 = t1.next
            if t2 is None:
                t2 = headA
            else:
                t2 = t2.next
            
        return t1
            
