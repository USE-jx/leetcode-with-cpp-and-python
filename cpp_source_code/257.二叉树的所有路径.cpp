/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
// };

/**
 * 前序递归
 * 
 */
class Solution {
public:
    //递归函数
    void traversal(TreeNode *node, vector<int> &path, vector<string> &result)
    {
        path.push_back(node->val);  //叶子节点也要加进去

        //没有子节点就是叶子节点了
        if (node->left == nullptr && node->right == nullptr) {
            string s_path;
            for (int i = 0; i < path.size() - 1; ++i) {
                s_path += to_string(path[i]);
                s_path += "->";
            }
            s_path += to_string(path[path.size()-1]);
            result.push_back(s_path);
        }
        if (node->left) {
            traversal(node->left, path, result);
            path.pop_back();
        }
        if (node->right) {
            traversal(node->right, path, result);
            path.pop_back();
        }

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<int> path;
        if (root == nullptr) return ans;
        traversal(root, path, ans);
        return ans;
    }
};
// @lc code=end

