#include<vector>
#include<string>
using namespace std;


// 首先要知道每个字母最后出现的位置，可以用string的rfind找到某个字母最后出现的下标
// 一个区间的断开点，应当是这个区间的最靠右的字符不在出现的位置
// 简单说就是断开点处的字母，就是这个区间中的字母查找结果最靠右的那个

// 想到算法：定义两个指针分别指向一个区间的开始和结束
// 遍历s，求s[i]的rfind，如果rfind大于当前记录end，更新end值为rfind，说明这个字母延长了区间范围
// 一直i++，直到i==end，说明这个区间的结束了，它里面的字母在i后不会再出现了。开始下一个区间的记录

class Solution {
public:
    vector<int> partitionLabels(string s) {
		// 定义每个区间的起始索引和结束索引
		int begin = 0, end = 0;
		// 定义返回的vector
		vector<int> v;
		for (int i = 0; i < s.size(); i++)
		{
			// 如果之前字母的结束区间，小于当前字母的结束区间，
			// 更新结束区间为更长的区间
			if (end < s.rfind(s[i]))
			{
				end = s.rfind(s[i]);
			}
			// 如果当前已经遍历到这个区间的结束位置，则断开，并记录一次
			if (end == i)
			{
				v.push_back(end - begin + 1);
				begin = end + 1;
			}
		}
		return v;
    }
};