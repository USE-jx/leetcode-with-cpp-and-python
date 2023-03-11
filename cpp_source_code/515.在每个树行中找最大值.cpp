/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 */

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode *> qu;
        if (root != nullptr)
            qu.push(root);
        while (!qu.empty())
        {
            int size = qu.size();
            int max = -__INT_MAX__-1;
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = qu.front();
                qu.pop();
                if (node->left)
                    qu.push(node->left);
                if (node->right)
                    qu.push(node->right);
                max = max < node->val ? node->val : max;
            }
            
            ans.push_back(max);
        }
        return ans;
    }
};
// @lc code=end

