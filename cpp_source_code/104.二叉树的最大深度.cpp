/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
 * 高度和深度相等
 * 方法一：后序递归
 * 左右中的顺序，左右节点深度取最大，中节点把最大深度加一，一直到根节点结束
 * 
 * 方法二： 前序递归
 * 中左右的顺序，递归函数得输入根节点和根节点的深度1，不断遍历左右节点
 * 更新深度。
 * 
 * 方法三：迭代层序遍历
 * 每遍历一层深度就加一
 */
class Solution {
public:
    //后序递归函数
    int getHeight(TreeNode *node ) {
        if (node == nullptr) return 0;
        return (1 + max(getHeight(node->left), getHeight(node->right)));
    }
    //前序递归函数
    //int ans;
    // void getDepth(TreeNode *node, int depth) {
    //     ans = depth > ans ? depth : ans; //中
    //     if (node->left == nullptr && node->right == nullptr) return ;
    //     if (node->left) {
    //         getDepth(node->left, depth + 1);
    //     }
    //     if (node->right) {
    //         getDepth(node->right, depth + 1);
    //     }
    //     return;
    // }
    int maxDepth(TreeNode* root) {
        // int ans = getHeight(root);
        // return ans;
        
        // ans = 0;
        // if (root == nullptr) return ans;
        // getDepth(root, 1);
        // return ans;
        int ans = 0;
        queue<TreeNode *> qu;
        if (root == nullptr) return 0;
        qu.push(root);
        while (!qu.empty()) {
            int size = qu.size();
            ++ans;
            for (int i = 0; i < size; ++i) {
                TreeNode *node = qu.front();
                qu.pop();
                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
            }

        }
        return ans;
        

    }
};
// @lc code=end

