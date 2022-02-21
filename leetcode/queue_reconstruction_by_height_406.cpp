#include<vector>
#include<algorithm>
using namespace std;


// Ҫ������������ͬʱ���ǵ�ǰ���м��������ߣ�����������Ҫ������һ��
// ��������Դﵽ���������ٸ���second��ֵ����΢������
// ����˼�������ǲ��ý������еķ�ʽ������������֣�������С���֣�
// ��Ϊ�źô����ֺ�����С���֣�С���ֱ仯����Դ����ֲ���Ӱ��

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		// ���彵�����й������Ȱ�������������һ��ʱ����second����
		// �Եڶ���Ԫ��Ҳ�����������Ҫ�������ڶ���Ԫ�����򣬵�һ��Ԫ�ؽ���
		class MyCompare
		{
		public:
			bool operator() (vector<int>& v1, vector<int>& v2)const {
				if (v1[0] > v2[0])
				{
					return true;
				}
				else if (v1[0] < v2[0])
				{
					return false;
				}
				else
				{
					return v1[1] > v2[1] ? false : true;
				}
			}
		};

		sort(people.begin(), people.end(), MyCompare());

		// ��ʼд�㷨
		vector<vector<int>> v;
		auto p = v.begin();
		for (int i = 0; i < people.size(); i++)
		{
			// Ҫ���룬���ܸ�ֵ
			v.insert((p + people[i][1]), people[i]);
			p = v.begin();
		}
		return v;
    }
};