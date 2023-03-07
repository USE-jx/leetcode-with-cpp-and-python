/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

/**
 * 思路：
 * 用map存储元素及其出现次数,然后对次数进行排序，最后输出次数大的k的元素
 * 主要是排序，
 * 基本实现是把各元素的次数放入一个数组，然后全排序，复杂度nlogn
 * 进阶实现是只维护一个k个元素的优先级队列，优先级队列基于堆实现，
 * 可以定义是大顶堆还是小顶堆，大顶堆就是二叉树根节点值最大，小顶堆
 * 根节点值最小，本次使用小顶堆，每次pop出k个之中最小的那个。
 * 
 */
class Solution {
public:
    //定义一个小顶堆的比较
    class MyComparision {
    public:
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans(k);
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            ++map[nums[i]];
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, MyComparision> pri_que;

        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); ++it) {
            pri_que.push(*it);
            if (pri_que.size() > k) {
                pri_que.pop();
            }
        }
        
        for (int i = k-1; i >=0; --i) {
            ans[i] = pri_que.top().first;
            pri_que.pop();
        }
        return ans;
    }
};
// @lc code=end

