/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

// Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* left;
//     Node* right;
//     Node* next;
// };


class Solution {
public:
    Node* connect(Node* root) {
        Node *ans;
        queue<Node *> qu;
        if (root != nullptr) {
            qu.push(root);
        }
        while (!qu.empty()) {
            
            int size = qu.size();
            for (int i = 0; i < size; ++i) {
                Node *node = qu.front();
                qu.pop();
                if (i < size - 1) {
                    node->next = qu.front();
                }
                
                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
                
            }
            
            
        }
        return root;
    }
};
// @lc code=end

