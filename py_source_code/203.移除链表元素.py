#
# @lc app=leetcode.cn id=203 lang=python3
#
# [203] 移除链表元素
#

# @lc code=start
# Definition for singly-linked list.



class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        dummyNode = ListNode(next=head)
        currentNode = dummyNode
        while (currentNode.next != None):
            if (currentNode.next.val == val):
                currentNode.next = currentNode.next.next
            else:
                currentNode = currentNode.next
        return dummyNode.next
        
# @lc code=end

