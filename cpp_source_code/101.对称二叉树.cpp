/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
#include <queue>
#include <stack>
using namespace std;
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// };

/**
 * 方法一：递归
 * 
 * 方法二：迭代
 * 一层一层加入栈或队列，弹出比较
 */
class Solution {
public:
    //递归函数
    bool compare(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right != nullptr) return false;
        else if (left != nullptr && right == nullptr) return false;
        else if (left == nullptr && right == nullptr) return true;
        else if (left->val != right->val) return false;

        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        return  outside && inside;
    }

    bool isSymmetric(TreeNode* root) {
        // bool ans = compare(root->left, root->right);
        bool ans;
        if (root == nullptr) return true;
        queue<TreeNode *> qu;
        stack<TreeNode *> st;
        qu.push(root->left);
        qu.push(root->right);
        while (!qu.empty()) {
            TreeNode *left_node = qu.front();
            qu.pop();
            TreeNode *right_node = qu.front();
            qu.pop();

            if (left_node == nullptr && right_node == nullptr) continue;
            if (left_node != nullptr && right_node == nullptr) return false;
            else if (left_node == nullptr && right_node != nullptr) return false;
            else if (left_node->val != right_node->val) return false;

            qu.push(left_node->left);
            qu.push(right_node->right);
            qu.push(left_node->right);
            qu.push(right_node->left);
        }
        return true;
        
    }
};
// @lc code=end

