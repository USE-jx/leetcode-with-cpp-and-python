/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector> 
#include <stack>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// };

/**
 * 方法一：递归
 * 
 * 方法二：迭代
 * 前序遍历顺序是中左右，可以用一个栈来辅助遍历。
 * 首先栈压入中节点，然后弹出中节点，存入数组，
 * 压入中节点的右节点，再压入左节点，弹出左节点。。。
 * 循环的过程是先弹出再压入，如果最后没有可以压入的节点，那么
 * 节点都弹出之后循环就结束了，所以循环条件是栈没空。
 * 
 */
class Solution {
public:
    // //递归函数
    // void traversal(TreeNode *cur, vector<int> &ans) {
    //     if (cur == nullptr) return;
    //     ans.push_back(cur->val);
    //     traversal(cur->left, ans);
    //     traversal(cur->right, ans);
    // }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        // traversal(root, ans);
        stack<TreeNode *> st;
        if (root == nullptr) return {};
        st.push(root);
        while (!st.empty()) {
            TreeNode *tn = st.top();
            ans.push_back(tn->val);
            st.pop();
            if (tn->right != nullptr) {
                st.push(tn->right);
            }
            if (tn->left != nullptr) {
                st.push(tn->left);
            }
        }
        


        return ans;
    }
};
// @lc code=end

