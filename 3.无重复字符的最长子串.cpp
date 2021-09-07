/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0, length = 0, result = 0;
        int ssize = s.length();
        unordered_map<char, int> hash;
        while(end < ssize) {
            char temp = s[end];
            if(hash.find(temp) != hash.end() && hash[temp] >= start){
                start = hash[temp] + 1;
                length = end - start;
            }
            hash[temp] = end;
            end++;
            length++;
            result = max(length, result);
        }
        return result;
    }
};
// @lc code=end

