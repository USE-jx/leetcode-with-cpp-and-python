/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
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


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node *> qu;
        if (root != nullptr) qu.push(root);
        while (!qu.empty()) {
            int size = qu.size();
            vector<int> tmp;
            for (int i = 0; i < size; ++i) {
                Node *node = qu.front();
                qu.pop();
                int sz = node->children.size();
                for (int i = 0; i < sz; ++i) {
                    if (node->children[i]) 
                    qu.push(node->children[i]);
                }
                tmp.push_back(node->val);
            }
            ans.push_back(tmp);
        }  
        return ans;
    }
};
// @lc code=end

