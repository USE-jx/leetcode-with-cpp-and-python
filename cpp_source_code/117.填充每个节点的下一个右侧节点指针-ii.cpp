/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node *ans;
        queue<Node *> qu;
        if (root != nullptr)
        {
            qu.push(root);
        }
        while (!qu.empty())
        {

            int size = qu.size();
            for (int i = 0; i < size; ++i)
            {
                Node *node = qu.front();
                qu.pop();
                if (i < size - 1)
                {
                    node->next = qu.front();
                }

                if (node->left)
                    qu.push(node->left);
                if (node->right)
                    qu.push(node->right);
            }
        }
        return root;
    }
};
// @lc code=end

