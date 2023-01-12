/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
/**
 * 双指针法
 * 判断有环：定义快慢指针，快指针一次走两个节点，慢指针一次走一个节点
 * 如果快指针和慢指针相遇就说明有环，而且一定在环里相遇，慢指针还没走一圈时
 * 判断入口节点：根据数学关系等式，一个指针从头开始右移，另一个指针从相遇点
 * 开始转圈，那么他俩的相遇点就是入口
*/
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && fast->next) {//fast快
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                ListNode *index1 = head;
                ListNode *index2 = fast;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return nullptr;
    }
};
// @lc code=end

