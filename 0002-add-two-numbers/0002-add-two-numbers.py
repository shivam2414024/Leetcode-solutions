# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(
        self, l1: ListNode | None, l2: ListNode | None
    ) -> ListNode | None:
        dummy = ListNode(0)
        prev = dummy
        carry = 0
        while l1 is not None or l2 is not None:
            a = l1.val if l1 is not None else 0
            b = l2.val if l2 is not None else 0
            sum = a + b + carry
            curr = ListNode(sum % 10)
            prev.next = curr
            prev = curr
            carry = sum // 10
            if l1 is not None:
                l1 = l1.next
            if l2 is not None:
                l2 = l2.next

        if carry != 0:
            curr = ListNode(carry)
            prev.next = curr

        return dummy.next
