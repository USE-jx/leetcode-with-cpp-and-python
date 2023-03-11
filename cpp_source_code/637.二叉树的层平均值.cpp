/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
// };

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode *> qu;
        if (root != nullptr) qu.push(root);
        while (!qu.empty()) {
            int size = qu.size();
            double sum = 0;
            for (int i = 0; i < size; ++i) {
                TreeNode *node = qu.front();
                qu.pop();
                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
                sum += node->val;
            }
            double mean = sum / size;
            ans.push_back(mean);
        }
        return ans;
    }
};
// @lc code=end

