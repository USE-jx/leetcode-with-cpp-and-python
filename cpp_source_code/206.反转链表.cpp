// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**
 * 思路：主要是从前向后遍历，操作next指针。
 * 但是链表的主要难点是改变next之后，原来的next节点就找不到了，所以
 * 需要提前存一下。
 * 前后两个节点一起向后移动。
 * 链表返回头指针不相当于返回一整个链表，leetcode是用头指针把链表遍历了一遍
 *
 */
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;

        while (cur != nullptr)
        {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
        cout << pre << endl;
    }
};

int main()
{
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    node1->next = node2;
    node2->next = nullptr;
    Solution::reverseList(node1);

    return 0;
}
