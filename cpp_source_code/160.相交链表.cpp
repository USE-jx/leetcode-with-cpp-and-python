/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };
/**
 * 
 * 
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pt_a = headA;
        ListNode *pt_b = headB; 
        int size_a = 0, size_b = 0;
        while (pt_a != nullptr) {
            pt_a = pt_a->next;
            ++size_a;
        }
        while (pt_b != nullptr) {
            pt_b = pt_b->next;
            ++size_b;
        }
        //关键别忘了，两个指针要重新指回头节点
        pt_a = headA;
        pt_b = headB;
        if (size_a < size_b) {
            int pre_move = size_b - size_a;
            while (pre_move--) 
            pt_b = pt_b->next;
        } else {
            int pre_move = size_a - size_b;
            while (pre_move--)
            pt_a = pt_a->next;
        }
        while (pt_a != nullptr) {
            if (pt_a == pt_b) {
                return pt_a;
            }
            pt_a = pt_a->next;
            pt_b = pt_b->next;
        }
        return nullptr;

    }
};
// @lc code=end

