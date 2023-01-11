#
# @lc app=leetcode.cn id=24 lang=python3
#
# [24] 两两交换链表中的节点
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummyhead = ListNode(next=head)
        cur = dummyhead
        while cur.next  and cur.next.next :
            temp1 = cur.next
            cur.next = cur.next.next
            temp2 = cur.next.next
            cur.next.next = temp1
            temp1.next = temp2
            cur = cur.next.next
        return dummyhead.next
# @lc code=end

