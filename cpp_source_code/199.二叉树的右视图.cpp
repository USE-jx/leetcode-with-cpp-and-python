/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
// };
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode *> qu;
        if (root == nullptr)
            return ans;
        qu.push(root);
        while (!qu.empty())
        {
            int size = qu.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = qu.front();
                qu.pop();
                if (node->left)
                    qu.push(node->left);
                if (node->right)
                    qu.push(node->right);
                if (i == size - 1) {
                    ans.push_back(node->val);
                }
                
            }
            
        }
        return ans;
    }
};
// @lc code=end

