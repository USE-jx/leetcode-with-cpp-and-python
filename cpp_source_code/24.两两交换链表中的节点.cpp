/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 */
/**
 * 交换位置就是操纵next，画图能更清楚操作顺序
 * 主要是改变完一个节点的next跨了一个节点，他下一个节点就找不到了，所以需要记录
 * 本题需要跨节点两次，所以记录两次
*/
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyhead = new ListNode(0,head);
        ListNode *cur = dummyhead;
        ListNode *temp1;
        ListNode *temp2;

        while (cur->next != nullptr && cur->next->next != nullptr) {
            temp1 = cur->next; //第一个节点记录上
            cur->next = cur->next->next;
            temp2 = cur->next->next; //记录3
            cur->next->next = temp1;
            temp1->next = temp2;
            cur = cur->next->next;
        }
        return dummyhead->next;
    }
};
// @lc code=end

