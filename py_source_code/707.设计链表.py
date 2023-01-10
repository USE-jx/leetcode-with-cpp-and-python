#
# @lc app=leetcode.cn id=707 lang=python3
#
# [707] 设计链表
#

# @lc code=start
# #方法一 单链表
# class ListNode:
#     def __init__(self, val):
#         self.val = val
#         self.next = None
        
# class MyLinkedList:

#     def __init__(self):
#         self.size = 0
#         self.head = ListNode(0)


#     def get(self, index: int) -> int:
#         if index < 0 or index >= self.size:
#             return -1
#         currentNode = self.head
#         for _ in range(index+1):
#             currentNode = currentNode.next
#         return currentNode.val


#     def addAtHead(self, val: int) -> None:
#         self.addAtIndex(0, val)
        

#     def addAtTail(self, val: int) -> None:
#         self.addAtIndex(self.size, val)

#     def addAtIndex(self, index: int, val: int) -> None:
#         if index > self.size:
#             return
#         if index < 0:
#             index = 0
#         currentNode = self.head
#         for _ in range(index):
#             currentNode = currentNode.next
#         newNode = ListNode(val)
#         newNode.next = currentNode.next
#         currentNode.next = newNode
#         self.size += 1


#     def deleteAtIndex(self, index: int) -> None:
#         if index < 0 or index >= self.size:
#             return
#         currentNode = self.head
#         for _ in range(index):
#             currentNode = currentNode.next
#         currentNode.next = currentNode.next.next
#         self.size -= 1

#方法二 双链表
class ListNode:
    def __init__(self, val) -> None:
        self.val = val
        self.prev = None
        self.next = None

class MyLinkedList:

    def __init__(self) -> None:
        self.size = 0
        self.head = ListNode(0)
        self.tail = ListNode(0)
        self.head.next = self.tail
        self.tail.prev = self.head
    
    def get(self, index:int) -> int:
        if index < 0 or index >= self.size:
            return -1
        if index+1 < self.size-index:
            cur = self.head
            for _ in range(index+1):
                cur = cur.next
        else:
            cur = self.tail
            for _ in range(self.size-index):
                cur = cur.prev
        return cur.val

    def addAtHead(self, val:int) -> None:
        self.addAtIndex(0,val)

    def addAtTail(self, val:int) ->None:
        self.addAtIndex(self.size, val)

    def addAtIndex(self, index:int, val:int) -> None:
        if index > self.size:
            return
        if index < 0:
            index = 0
        if index < self.size - index:
            pred = self.head
            for _ in range(index):
                pred = pred.next
            succ = pred.next
        else:
            succ = self.tail
            for _ in range(self.size - index):
                succ = succ.prev
            pred = succ.prev
        newNode = ListNode(val)
        newNode.next = succ
        newNode.prev = pred
        pred.next = newNode
        succ.prev = newNode
        self.size += 1

    def deleteAtIndex(self, index:int) ->None:
        if index < 0 or index >= self.size:
            return
        if index < self.size - index:
            pred = self.head
            for _ in range(index):
                pred = pred.next
            succ = pred.next.next
        else:
            succ = self.tail
            for _ in range(self.size - index-1):
                succ = succ.prev
            pred = succ.prev.prev
        pred.next = succ
        succ.prev = pred
        self.size -= 1


            


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
# @lc code=end

