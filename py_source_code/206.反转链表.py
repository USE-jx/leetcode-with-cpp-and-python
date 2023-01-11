#
# @lc app=leetcode.cn id=206 lang=python3
#
# [206] 反转链表
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
# class Solution:
#     def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
#         #双指针法
#         pre = None
#         cur = head
#         while (cur):
#             temp = cur.next
#             cur.next = pre
#             pre = cur
#             cur = temp
#         return pre
class Solution:
    def reverse(self, pre:ListNode, cur:ListNode) -> ListNode:
        if (cur == None):
            return pre
        temp = cur.next
        cur.next = pre
        return self.reverse(cur, temp)
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        #递归实现
        return self.reverse(None, head)
# @lc code=end

