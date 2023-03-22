/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */

// @lc code=start
#include <queue>
using namespace std;

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
// };

/**
 * 方法一：层序遍历
 * 没啥难度，每层的个数都加一起就行了
 * 
 * 方法二：后序递归
 * 先判断一下是不是全二叉树，如果左侧深度和右侧深度相等，那就是
 * 完全二叉树，直接用公式2^n - 1计算
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        // int ans = 0;
        // queue<TreeNode *> qu;
        // if (root == nullptr) return 0;
        // qu.push(root);
        // while (!qu.empty()) {
        //     int size = qu.size();
        //     for (int i = 0; i < size; ++i) {
        //         TreeNode *node = qu.front();
        //         qu.pop();
        //         ++ans;
        //         if (node->left) qu.push(node->left);
        //         if (node->right) qu.push(node->right);
        //     }
        // }
        // return ans;
        if (root == nullptr) return 0;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        int l_depth = 0, r_depth = 0;
        while (left) {
            left = left->left;
            ++l_depth;
        }
        while (right)
        {
            right = right->right;
            ++r_depth;
        }
        if (l_depth == r_depth) {
            return (2 << l_depth ) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
        

    }
};
// @lc code=end

