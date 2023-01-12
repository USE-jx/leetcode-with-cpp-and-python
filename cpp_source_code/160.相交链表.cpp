/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 */
/**
 * 方法一：暴力解法
 * 双层循环，大循环A链表，小循环B链表，如果节点地址相同就返回该节点
 * 注意小循环后要把B链表指针重新指向头节点
 * 方法二：双指针
 * 两个链表长度可能不相等，但用两个指针都遍历完一个链表再遍历
 * 另一个链表的话，它们到达相交节点的时间就对上了
*/
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // //暴力解法
        // ListNode *ptrA = headA;
        // ListNode *ptrB = headB;
        // while (ptrA != nullptr) {
            
        //     while (ptrB != nullptr){
                
        //         if ( ptrA == ptrB ) {
        //             return ptrA;
        //         }
        //         ptrB = ptrB->next;
        //     }
        //     ptrB = headB;
        //     ptrA = ptrA->next;
        // }
        // return nullptr;
        //方法二：双指针
        ListNode *ptrA = headA;
        ListNode *ptrB = headB;
        if (ptrA == nullptr || ptrB == nullptr) 
            return nullptr;
        while (ptrA != ptrB) {
            if (ptrA != nullptr) {
                ptrA = ptrA->next;
            } else ptrA = headB;
            if (ptrB != nullptr) {
                ptrB = ptrB->next;
            } else ptrB = headA;
        }
        return ptrA;

    }
};
// @lc code=end

