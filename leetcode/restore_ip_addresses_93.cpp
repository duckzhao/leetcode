#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
		vector<string> retval;
		// 当前正在分割哪个stage
		int stage = 0;
		// 最多截取三个字母
		for (int i = 0; i < 3; i++)
		{
			vector<string> retval2 = backTrack(s, stage, 0, i + 1);
			if (!retval2.empty())
			{
				retval.insert(retval.end(), retval2.begin(), retval2.end());
			}
		}
		return retval;
    }

	// 判断传入的区间是否合格，并对后面的区间进行dfs分割,lastend表示截取几个
	vector<string> backTrack(string& s, int stage, int lastend, int size) {
		vector<string> res;
		// 判断剩余的字符串数量是否满足需求
		int others = s.size() - lastend - size;
		if (others < 3 - stage || others > 9 - stage * 3)
		{
			return res;
		}
		// 剩余区间数量如果满足需求的话，再判断当前截取的子字符串是否满足规则0-255，且没有前导0
		string temp = s.substr(lastend, size);
		int number = stoi(temp);
		if (temp.size() > 1 && temp[0] == '0' || number > 255)
		{
			return res;
		}
		// 开始判断 temp 对应的 下一个stage
		stage++;
		// 最多截取三个字母

		if (stage == 3)
		{
			string temp_s = s.substr(lastend + size, s.size() - lastend - size);
			if (temp_s.size() > 1 && temp_s[0] == '0' || stoi(temp_s) > 255)
			{
				return res;
			}
			res.push_back(temp_s);
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				vector<string> temp_v = backTrack(s, stage, lastend + size, i + 1);
				if (!temp_v.empty())
				{
					res.insert(res.end(), temp_v.begin(), temp_v.end());
				}
			}
		}
		for (int j = 0; j < res.size(); j++)
		{
			res[j] = temp + "." + res[j];
		}
		return res;
	}
};

int main93() {
	Solution s;
	s.restoreIpAddresses("25525511135");

	return 0;
}