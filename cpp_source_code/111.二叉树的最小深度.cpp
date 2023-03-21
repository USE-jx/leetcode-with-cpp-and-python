/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

// @lc code=start
#include <queue>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
// };

/**
 * 方法一：层序迭代
 * 关键是层序遍历放入queue时，如果一个节点的左右节点
 * 都没有，那就直接返回这个节点的深度
 * 方法二：后序递归
 * 
 */
class Solution {
public:
    //递归函数
    int getHeight(TreeNode *node) {
        if (node == nullptr) return 0;
        int l_height = getHeight(node->left);
        int r_height = getHeight(node->right);
        if (node->left == nullptr && node->right != nullptr) {
            return 1 + r_height;
        } 
        if (node->left != nullptr && node->right == nullptr) {
            return 1 + l_height;
        }
        return 1 + min(l_height, r_height);
        

    }
    int minDepth(TreeNode* root) {
        // int ans = 0;
        // if (root == nullptr) return ans;
        // queue<TreeNode *> qu;
        // qu.push(root);
        // while (!qu.empty()) {
        //     int size = qu.size();
        //     ++ans;
        //     for (int i = 0; i < size; ++i) {
        //         TreeNode *node = qu.front();
        //         qu.pop();
        //         if (node->left) qu.push(node->left);
        //         if (node->right) qu.push(node->right);
        //         if (!node->left && !node->right) return ans;
        //     }
        // }
        // return ans;
        int ans = getHeight(root);
        return ans;
    }
};
// @lc code=end

