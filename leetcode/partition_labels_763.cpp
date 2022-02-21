#include<vector>
#include<string>
using namespace std;


// ����Ҫ֪��ÿ����ĸ�����ֵ�λ�ã�������string��rfind�ҵ�ĳ����ĸ�����ֵ��±�
// һ������ĶϿ��㣬Ӧ��������������ҵ��ַ����ڳ��ֵ�λ��
// ��˵���ǶϿ��㴦����ĸ��������������е���ĸ���ҽ����ҵ��Ǹ�

// �뵽�㷨����������ָ��ֱ�ָ��һ������Ŀ�ʼ�ͽ���
// ����s����s[i]��rfind�����rfind���ڵ�ǰ��¼end������endֵΪrfind��˵�������ĸ�ӳ������䷶Χ
// һֱi++��ֱ��i==end��˵���������Ľ����ˣ����������ĸ��i�󲻻��ٳ����ˡ���ʼ��һ������ļ�¼

class Solution {
public:
    vector<int> partitionLabels(string s) {
		// ����ÿ���������ʼ�����ͽ�������
		int begin = 0, end = 0;
		// ���巵�ص�vector
		vector<int> v;
		for (int i = 0; i < s.size(); i++)
		{
			// ���֮ǰ��ĸ�Ľ������䣬С�ڵ�ǰ��ĸ�Ľ������䣬
			// ���½�������Ϊ����������
			if (end < s.rfind(s[i]))
			{
				end = s.rfind(s[i]);
			}
			// �����ǰ�Ѿ��������������Ľ���λ�ã���Ͽ�������¼һ��
			if (end == i)
			{
				v.push_back(end - begin + 1);
				begin = end + 1;
			}
		}
		return v;
    }
};