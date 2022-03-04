#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
		vector<string> retval;
		// ��ǰ���ڷָ��ĸ�stage
		int stage = 0;
		// ����ȡ������ĸ
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

	// �жϴ���������Ƿ�ϸ񣬲��Ժ�����������dfs�ָ�,lastend��ʾ��ȡ����
	vector<string> backTrack(string& s, int stage, int lastend, int size) {
		vector<string> res;
		// �ж�ʣ����ַ��������Ƿ���������
		int others = s.size() - lastend - size;
		if (others < 3 - stage || others > 9 - stage * 3)
		{
			return res;
		}
		// ʣ���������������������Ļ������жϵ�ǰ��ȡ�����ַ����Ƿ��������0-255����û��ǰ��0
		string temp = s.substr(lastend, size);
		int number = stoi(temp);
		if (temp.size() > 1 && temp[0] == '0' || number > 255)
		{
			return res;
		}
		// ��ʼ�ж� temp ��Ӧ�� ��һ��stage
		stage++;
		// ����ȡ������ĸ

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