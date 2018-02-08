/*
题目描述
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
思路
字符串的模式匹配问题:

典型的KMP算法问题, 给出两种解法, 简单的朴素匹配和KMP算法匹配.
*/

//朴素匹配
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();
        if(n == 0) return 0;
        for(int i = 0; i < m - n + 1; i++){
            int j = 0;
            for(; j < n; j++){
                if(haystack[i + j] != needle[j])
                    break;
            }   
            if(j == n)
                return i;
        }
        return -1;
    }
};
//KMP算法
class Solution {
private:
    void NEXT(const string&T, vector<int>&next){//按模式串生成vector,next(T.size())
    for(int i = 1, len = 0; i < T.size();){
        if(T[i] == T[len]){
		next[i++] = ++len;
        }
        else if(len){
		len = next[len - 1];
        }
        else
		i++;
    }
}    
public:
    int strStr(string S, string T) {//返回T在S中第一次出现的下标
        vector<int>next(T.size(), 0);
        if(!T.size()) return 0;
        NEXT(T, next);
        for(int i = 0; i < S.size(); i++){
		for(int j = 0; j < T.size();){
			if(S[i+j] == T[j]){
				j++;
				if(j == T.size())
					return i;
			}
			else{
				i += next[j];
				break;
			}
		}
        }
        return -1;
    }
};
