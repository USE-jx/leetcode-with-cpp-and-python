/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 */

// @lc code=start

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
// };


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
    
        
         queue<TreeNode *> qu;
         if (root == nullptr) return ans;
         qu.push(root);
         while (!qu.empty()) {
             int size = qu.size();
             vector<int> tmp;
             for (int i = 0; i < size; ++i) {
                 TreeNode *node = qu.front();
                 qu.pop();
                 if (node->left) qu.push(node->left);
                 if (node->right) qu.push(node->right);
                 tmp.push_back(node->val);
             }
             ans.push_back(tmp);
         }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

