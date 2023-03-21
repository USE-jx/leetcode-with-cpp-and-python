/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;
// Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> children;

//     Node() {}

//     Node(int _val) {
//         val = _val;
//     }

//     Node(int _val, vector<Node*> _children) {
//         val = _val;
//         children = _children;
//     }
// };

/**
 * 方法一：后序递归
 * 
 * 方法二：层序迭代
 * 
 */
class Solution {
public:
    int maxDepth(Node* root) {
        // if (root == nullptr) return 0;
        // int depth = 0;
        // for (int i = 0; i < root->children.size(); ++i) {
        //     depth = max(maxDepth(root->children[i]),depth);
        // }
        // return depth + 1;
        int ans = 0;
        queue<Node *> qu;
        if (root == nullptr) return 0;
        qu.push(root);
        while (!qu.empty()) {
            int size = qu.size();
            ++ans;
            for (int i = 0; i < size; ++i) {
                Node *node = qu.front();
                qu.pop();
                for (int j = 0; j < node->children.size(); ++j) {
                    if (node->children[j]) qu.push(node->children[j]);
                }
            }
            
        }
        return ans;
    }
};
// @lc code=end

