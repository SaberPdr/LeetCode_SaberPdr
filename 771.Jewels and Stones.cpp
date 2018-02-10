/*
题目描述
给出两个 string J 和 S, 计算 S 中有多少元素是 J 中有的.

思路
这道题应该是 leetcode上最简单的题了吧, 难度为 easy 并且通过率在 80% 以上.

我们几乎一眼就能看出来解法, 毕竟这是初学字符串时几乎都会做的一道题. 解法就是对于 J 中的每一个元素扫描一遍 S, 有相同的就把返回值 +1. 把 J 和 S 的长度记为 m 和 n, 那么复杂度是O(mn).

但是这么做在 m 和 n 比较大的时候就不太好了. 注意到题中给出条件: J 中没有重复元素, 因此我们尝试使用集合 set 来保存 string J 中的元素, 对 S 中的每个元素 , 计算 setJ.count(), 所有元素的 count 的和就是答案. 在以红黑树为底层实现的 set 中, 复杂度是O(nlog(m)), 在以 hashtable 为底层实现的 set 中, 复杂度是O(n). (我也不知道在 leetcode 的 c++ 库中使用的是哪个版本的 STL, 所以也不知道这段代码的具体复杂度:)
*/
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        set<char> setJ(J.begin(), J.end());
        for(int i = 0; i < S.length(); i++)
		if(setJ.count(S[i]))
			res++;
        return res;
    }
};
