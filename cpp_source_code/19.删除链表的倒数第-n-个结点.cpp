/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
 * 方法一：暴力解法
 * 先得到链表的size，再找到正数第（size-n）个节点，这个是倒数第
 * n个节点前边一个节点，然后先把要删除的节点记录，next跨过这个节点
 * 最后删除内存，返回头节点
 * 
 * 方法二：巧妙双指针法
 * 因为涉及到删除头节点的问题，所以需要new一个虚拟头节点
 * 定义快慢指针都指向虚拟头节点，快指针先走n步，然后快慢指针
 * 保持这个距离已知向后遍历，直到快指针指向null，后来发现
 * 删除节点需要找到前一个节点，所以需要快指针先走n+1步
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // //方法一
        // ListNode *dummyhead = new ListNode(0,head);
        // ListNode *cur1 = head;
        // ListNode *cur2 = dummyhead;
        // int size = 0;
        // while (cur1) {
        //     cur1 = cur1->next;
        //     ++size;
        // }
        // int forwardNum = size - n;
        // while (forwardNum--) cur2 = cur2->next;
        // ListNode *temp = cur2->next;
        // cur2->next = cur2->next->next;
        // delete temp;
        // return dummyhead->next;
        //方法二：双指针
        ListNode *dummyhead = new ListNode(0, head);
        ListNode *fast = dummyhead;
        ListNode *slow = dummyhead;
        n++; //快指针多走一步
        while (n-- ) { //不用限制fast，因为n不能超过size-1
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return dummyhead->next;          
    }
};
// @lc code=end

