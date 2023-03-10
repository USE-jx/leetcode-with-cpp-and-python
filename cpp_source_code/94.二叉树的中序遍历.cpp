/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
#include <vector> 
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
 * 遍历从根节点开始，存储顺序不是从根节点开始，所以需要用
 * 栈存储节点，到左节点为null时弹出左节点，存入数组，然后
 * 存中节点，再存右节点
 * 
 */
class Solution {
public:
    //递归函数
    void traversal(TreeNode *cur, vector<int> &ans) {
        if (cur == nullptr) return;
        traversal(cur->left, ans);
        ans.push_back(cur->val);
        traversal(cur->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        // traversal(root, ans);
        stack<TreeNode *> st;
        TreeNode *cur = root;
        
        if (root == nullptr) return {};
        while (!st.empty() || cur != nullptr) {
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ans;
    }
};
// @lc code=end

