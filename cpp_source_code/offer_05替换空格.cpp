// @algorithm @lc id=100280 lang=cpp
// @title ti-huan-kong-ge-lcof

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    string replaceSpace(string s)
    {
        string ans;
        for (char c : s)
        {
            if (c == ' ')
            {
                ans.push_back('%');
                ans.push_back('2');
                ans.push_back('0');
            }
            else
            {
                ans.push_back(c);
            }
        }
        return ans;
    }
};