/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
#include <unordered_set>
using namespace std;

/**
 * 
 * 哈希表可以快速判断一个数是否出现在表里，所以本题可以用
 * 哈希表判断平方和是否出现过，如果出现过则会进入循环，直接
 * 返回false，最后平方和变成1就返回false
 * 
 */
class Solution {
public:
    //写一个求和函数
    int getSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> sum_set;
        // while (1) {
        //     int sum = getSum(n);
        //     if (sum == 1) {
        //         return true;
        //     }

        //     if (sum_set.find(sum) != sum_set.end()) {
        //         return false;
        //     } else {
        //         sum_set.insert(sum);
        //     }
        //     n = sum;
        // }
        while (n != 1 && sum_set.find(n) == sum_set.end()) {
            sum_set.insert(n);
            n = getSum(n);           
        }
        return n == 1;
    }
};
// @lc code=end

