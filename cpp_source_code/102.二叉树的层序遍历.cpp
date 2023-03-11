/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// };
/**
 * 方法一：迭代法
 * 用一个队列存储，每一层的数量记住，就可以知道弹出一层需要几次
 * 
 * 方法二：递归
 * 记录一下层数深度，每一层
 * vector用下标时记得要初始化，本题二维数组放入一个一维空数组
 * 完成了初始化。
 */
class Solution {
public:
    //递归函数
    void order(TreeNode *cur, vector<vector<int>> &ans, int depth) {
        if (cur == nullptr) return;
        if (ans.size() == depth) ans.push_back(vector<int>());
        ans[depth].push_back(cur->val);
        order(cur->left, ans, depth+1);
        order(cur->right, ans, depth+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        order(root, ans, 0);
        //迭代法
        // queue<TreeNode *> qu;
        // if (root == nullptr) return ans;
        // qu.push(root);
        // while (!qu.empty()) {
        //     int size = qu.size();
        //     vector<int> tmp;
        //     for (int i = 0; i < size; ++i) {
        //         TreeNode *node = qu.front();
        //         qu.pop();
        //         if (node->left) qu.push(node->left);
        //         if (node->right) qu.push(node->right);
        //         tmp.push_back(node->val);
        //     }
        //     ans.push_back(tmp);
        // }
        return ans;
    }
};
// @lc code=end

