#
# @lc app=leetcode.cn id=160 lang=python3
#
# [160] 相交链表
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        #双指针
        ptrA = headA
        ptrB = headB
        if ptrA == None or ptrB == None:
            return None

        while ptrB != ptrA:
            if ptrA != None:
                ptrA = ptrA.next
            else:
                ptrA = headB
            if ptrB != None:
                ptrB = ptrB.next
            else:
                ptrB = headA
        return ptrB
        
# @lc code=end

