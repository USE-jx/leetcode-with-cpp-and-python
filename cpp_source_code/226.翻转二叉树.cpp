/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
 * 方法一：递归， 前中后序皆可实现
 * 
 * 方法二：迭代
 * 
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        //递归 前序
        // if (root == nullptr) return root;
        // swap(root->left, root->right);
        // invertTree(root->left);
        // invertTree(root->right);
        // return root;
        //递归中序
        // if (root == nullptr)
        //     return root;
        // invertTree(root->left);
        // swap(root->left, root->right);
        // invertTree(root->left);
        // return root;
        //递归 后序
        // if (root == nullptr)
        //     return root;
        // invertTree(root->left);
        // invertTree(root->right);
        // swap(root->left, root->right);
        // return root;
        //迭代 前序
        // stack<TreeNode *> st;
        // if (root != nullptr) st.push(root);
        // while (!st.empty()) {
        //     TreeNode *node = st.top();
        //     st.pop();
        //     swap(node->left, node->right);
        //     if (node->right) st.push(node->right);
        //     if (node->left) st.push(node->left);
        // }
        // return root;
        //迭代 层序
        queue<TreeNode *> qu;
        if (root != nullptr)
            qu.push(root);
        while (!qu.empty())
        {
            TreeNode *node = qu.front();
            qu.pop();
            swap(node->left, node->right);
            if (node->left)
                qu.push(node->left);
            if (node->right)
                qu.push(node->right);
            
        }
        return root;
    }
};
// @lc code=end

