Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
 

Example:

Input: "cbbd"

Output: "bb"
题目描述
给定一个字符串 s, 找到 s 的最长回文子串.

/*
思路
这个解法并不是最优解, 但是很好理解, 基本上结合着注释就能看懂.

对于字符串中的每个字符, 计算以当前字符为结尾的回文长度, 仅有一个字符时长度为1.

当前遍历过的字符的最长回文长度赋给 maxLen, 子串的起点下标和终点下标赋给 a 和 b.

对于如何避免在判断一个子串是否是回文时的重复比较, 使用了一个辅助二维 bool 数组 pal 记录s[i...j]是否是回文串.

这个解法的时间复杂度和空间复杂度都是 O(n^2). 有一个 Manacher 算法是 O(n) 的, 我会另写一篇.

*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        //pal[i][j] 表示s[i...j]是否是回文串
        int maxLen = 0;
        int start = 0;
        for(int i = 0; i < n; i++){    //i 作为终点
            int j = i;                 //j 作为起点
            while(j >= 0){
                if(s[j] == s[i] && (i - j < 2 || pal[j + 1][i - 1])){
                //如果第j个字符和第i个字符相同, 且j和i之间的子串s[j+1...i-1]是回文
                    pal[j][i] = true;//那么s[j...i]就是一个回文子串
                    if(maxLen < max(maxLen, i-j+1)){
                        //如果新的回文更长, 更新长度和子串的开始位置
                        maxLen = max(maxLen, i-j+1);
                        start = j;
                    }
                }
                j--;
            }
        }
        string res(s, start, maxLen);
        return res;
    }
};
