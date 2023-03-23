/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
// };

/**
 * 后序递归
 * 用返回-1 表示不是平衡二叉树
 * 一直从根节点递归到底，向上返回时一旦左右子树高度差超过一
 * 就返回负一，
 * 如果左右子树得到高度为-1需要直接返回-1，否则左-1，右0
 * 也会得到是平衡二叉树
 */
class Solution {
public:
    //递归函数
    int getHeight(TreeNode *node) {
        if (node == nullptr) return 0;
        int l_height = getHeight(node->left);
        if (l_height == -1) return -1;
        int r_height = getHeight(node->right);
        if (r_height == -1) return -1;
        if (abs(l_height - r_height) > 1) {
            return -1;
        } else {
            return 1+ max(l_height,r_height);
        }
    }
    bool isBalanced(TreeNode* root) {
        int height = getHeight(root);
        if (height == -1) return false;
        else return true;
    }
};
// @lc code=end

