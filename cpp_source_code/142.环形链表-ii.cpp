/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start

  // struct ListNode {
  //     int val;
  //     ListNode *next;
  //     ListNode(int x) : val(x), next(nullptr) {}
  // };
/**
 * 思路：
 * 1. 判断是否有环
 * 定义快慢指针，快指针一次两步，慢指针一次一步，快慢指针相遇证明有环
 * 2. 得到入环点
 * 设头节点到入环点节点数x，入环点到相遇点节点数y，环的另一段节点数
 * 为z，n为快慢指针相遇快指针转的圈数，可得等式2*(x+y) = x + y + n * (y+z),
 * 推出x = n*(y+z)-y,因为快指针先入环，所以慢指针入环，快指针和慢指针相遇时
 * 快指针至少又经过了入环点一次才能追慢指针，也就是快指针追到慢指针时至少转了
 * 1圈，设n=1，则推出x=z。
 * 3. n只能为1吗
 * n根据环的大小可能是任意值，取1只是比较方便。我们只是通过这个等式推导出
 * 以从x出发和从z出发的两个同速指针最后一定会在入环口相遇，如果n不是1，那么
 * 从z出发的指针只是多在环里转了几圈，最后还是会在环口相遇。
 * 
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        //判断是否有环
        while (fast != nullptr && fast->next != nullptr) {
          fast = fast->next->next;
          slow = slow->next;
          if (fast == slow) {
            // 判断入环口
            ListNode *node1 = head;
            while (node1 != slow)
            {
              node1 = node1->next;
              slow = slow->next;
            }
            return slow;
          }

        } 

        return nullptr;
        
    }
};
// @lc code=end

