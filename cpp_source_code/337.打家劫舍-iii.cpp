/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
#include <vector>
using namespace std;

//   struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode() : val(0), left(nullptr), right(nullptr) {}
//       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  };
 
class Solution {
public:
    //后序遍历得到偷和不偷的最大金额
    vector<int> robTree(TreeNode *cur) {
        if (cur == nullptr) return {0,0};

        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);

        //偷cur
        int val1 = cur->val + left[0] + right[0];

        //不偷cur
        int val2 = max(left[0],left[1]) + max(right[0], right[1]);
        return {val2, val1};

    }

    int rob(TreeNode* root) {
        vector<int> result = robTree(root);
        return max(result[0], result[1]);
    }
};
// @lc code=end

