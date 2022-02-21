#include<vector>
#include<string>
using namespace std;

// 判断两个字符串的子序列问题，直接上双指针->即两个vector容器的比较问题都可以上双指针试试
class Solution {
public:
    bool isSubsequence(string s, string t) {
		int i = 0, j = 0;
		while (i < s.size() && j < t.size())
		{
			if (s[i] == t[j])
			{
				i++;
				j++;
			}
			else
			{
				j++;
			}
		}
		return i == s.size();
    }
};