/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
/**
 * 方法1：
 * 需要判断删除的节点是不是头节点，
 * 如果是头节点，需要把head指针指向下一个节点，释放掉头节点内存
 * 如果不是头节点，构造一个当前节点指针，从头开始遍历，循环条件是当前和next都不是空指针
 * 如果当前节点的下一个节点值为val，那就将当前节点的next变为next的next，
 * 在释放掉被删节点的内存，当然这个需要没删除之前记录一下
 * 方法2：
 * 设置一个虚拟的头节点，这样就不用判断是不是头节点了
 * 虚拟头节点的next为head，构造一个当前节点指针初始指向虚拟头节点
 * 遍历过程同上
 * 遍历结束之后令真实头节点为虚拟头节点的next，删除虚拟头节点的内存
 * 
*/
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution {
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // 方法2
        //构造一个虚拟头节点next为头节点
        ListNode *dummyNode = new ListNode();
        dummyNode->next = head;
        // 构造一个当前节点指针
        ListNode *currentNode = dummyNode;
        while (currentNode->next != nullptr)
        {
            if (currentNode->next->val == val)
            {
                ListNode *toBeDelete = currentNode->next;
                currentNode->next = currentNode->next->next;
                delete toBeDelete;
            }
            else
            {
                currentNode = currentNode->next;
            }
        }
        head = dummyNode->next;
        delete dummyNode;
        return head;
    }
    // ListNode* removeElements(ListNode* head, int val) {
    //     //方法1
    //     //删除头节点
    //     while (head != nullptr && head->val == val) {
    //         ListNode *toBeDelete = head;
    //         head = head->next;
    //         delete toBeDelete;
    //     }
    //     //删除其他节点
    //     //构造一个当前节点指针
    //     ListNode *currentNode = head;
    //     while (currentNode != nullptr && currentNode->next != nullptr)
    //     {
    //         if (currentNode->next->val == val) {
    //             ListNode *toBeDelete = currentNode->next;
    //             currentNode->next = currentNode->next->next;
    //             delete toBeDelete;
    //         } else {
    //             currentNode = currentNode->next;
    //         }
    //     }
    //     return head;
    // }
};
// @lc code=end

