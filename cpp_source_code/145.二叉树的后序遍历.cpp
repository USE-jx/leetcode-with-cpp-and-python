/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// };

class Solution {
public:
    // 递归函数
    void traversal(TreeNode *cur, vector<int> &ans) {
        if (cur == nullptr) return;
        traversal(cur->left, ans);
        traversal(cur->right, ans);
        ans.push_back(cur->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        // traversal(root, ans);
        stack<TreeNode *> st;
        st.push(root);
        if (root == nullptr) return {};
        while (!st.empty()) {
            TreeNode * tn = st.top();
            ans.push_back(tn->val);
            st.pop();
            if (tn->left != nullptr)
            {
                st.push(tn->left);
            }
            if (tn->right != nullptr) {
                st.push(tn->right);
            }
            
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};
// @lc code=end

