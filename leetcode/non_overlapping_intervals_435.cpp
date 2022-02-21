#include<vector>
#include<algorithm>
using namespace std;

// ����������Ƴ���С��Ԫ��ʹ��ʣ�µ����䲻�ص�����Ȼ�ܹ��뵽����ÿ��Ԫ�ص�begin��endֵ
// ��С�йأ���������뵽���������vector�д�ŵ��ǳ���Ϊ2��vector����Ҫ���������Ҫ��
// ���������򣬲��Լ�д�º���ʵ�֡����ǰ���begin�Ĵ�С����Ԫ������
// �㷨���ģ������������i��λ�ã��Ƚ�i.second��i+1.first�Ĵ�С�����i.second<=1.first��
// �����������䲻�ص����������µ�����i++�����i.second>1.first��˵���������������ص���
// ��ô����������һ��Ҫȥ��һ����������������ִ��ȥ��������ȥ������second�����Ԫ�أ�
// �����Ϳ��Ը������Ԫ�����¸���Ŀռ�,����Ԫ�ص�first��������������ǰ��Ԫ��second������

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		
		class MyCompare
		{
		public:
			bool operator() (vector<int>& v1, vector<int>& v2) const {
				return v1[0] < v2[0];
			}
		};

		sort(intervals.begin(), intervals.end(), MyCompare());

		vector<int> v = intervals[0];
		int count = 0;

		for (int i = 1; i < intervals.size(); i++)
		{
			if (v[1] <= intervals[i][0])
			{
				v = intervals[i];
				continue;
			}
			else
			{
				count++;
				if (v[1] >= intervals[i][1])
				{
					v = intervals[i];
				}
			}
		}
		return count;

    }
};