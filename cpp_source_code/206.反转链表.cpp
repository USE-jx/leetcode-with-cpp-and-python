/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
/**
 * 方法1：双指针法
 * 用两个指针pre和cur分别指向当前节点前一个节点和当前节点，
 * 两个指针挨着向后遍历链表，当cur=null时停止，
 * 在反转之前需要先记录一下cur.next，否则cur指向pre后，cur就没法后移了，
 * 然后先pre=cur，再cur=temp
 * 方法2：递归
 * 按照双指针的实现思路用递归的形式写出代码
 * 因为本次需要不断更新pre和cur，所以两个参数设为pre和cur
*/
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr){} 
//     ListNode(int x) : val(x), next(nullptr){} 
//     ListNode(int x, ListNode *next) : val(x), next(next){}                                                                                                                                    *
// };

class Solution {
public:
    ListNode *reverse(ListNode *pre, ListNode *cur)
    {
        if (cur == nullptr)
            return pre;
        ListNode *temp = cur->next;
        cur->next = pre;
        return reverse(cur, temp);
    }
    ListNode* reverseList(ListNode* head) {
        // //双指针
        // ListNode *pre = nullptr;
        // ListNode *cur = head;
        // ListNode *temp;
        // while (cur) {
        //     temp = cur->next;
        //     cur->next = pre;
        //     pre = cur;
        //     cur = temp;
        // }
        // return pre;
        
        //递归
        //函数外定义一个reverse函数
        //调用reverse，传入参数pre=null,cur=head
        return reverse(nullptr, head);
        
    }
};
// @lc code=end

