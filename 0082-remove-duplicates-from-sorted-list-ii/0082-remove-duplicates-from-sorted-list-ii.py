# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode | None) -> ListNode | None:
        if head is None:
            return head
        prev = head
        curr = head

        while curr is not None and curr.next is not None:
            if head.val == curr.val and curr.val == curr.next.val:
                while curr.next is not None and curr.val == curr.next.val:
                    curr = curr.next
                head = curr.next
                prev.next = curr.next

            elif curr.val == curr.next.val:
                while curr.next is not None and curr.val == curr.next.val:
                    curr = curr.next
                prev.next = curr.next

            else:
                prev = curr

            curr = curr.next

        return head
