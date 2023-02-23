/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {} 
//     ListNode(int x) : val(x), next(nullptr) {} 
//     ListNode(int x, ListNode *next) : val(x), next(next) {}                                                                                                                                
// };
/**
 * 思路：正常找倒数第n个节点需要先遍历到尾节点，记录一下节点
 * 个数，然后再去删除节点数-n个节点。
 * 删除节点需要找到要删除节点的前一个结点，前一个结点直接指向
 * 当前节点的下一个节点就删除了当前节点。
 * 但是如果只扫描一次链表的话就需要使用双指针了，一个指针先走
 * n步第二个指针才开始走，两个指针一起同步走，第一个指针走到
 * 结尾的时候第二个指针正好走到倒数第n个节点，但是由于需要找
 * 到删除节点的前一个节点，所以需要第一个节点先走n+1步。
 * 
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy_head = new ListNode(0, head);
        ListNode *fast = dummy_head;
        ListNode *slow = dummy_head;
        ++n;
        while (n-- && fast != nullptr) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        return dummy_head->next;
        
    }
};
// @lc code=end

