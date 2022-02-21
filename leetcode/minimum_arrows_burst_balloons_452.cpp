#include<vector>
#include<algorithm>
using namespace std;

// ��Ҫ�ҵ����ٵ��������������Ҫ�ҵ�ÿһ���ܹ�ʹ���ص���ʽ��һ���䴩��������ࡣ
// ��˿϶���Ҫ��ԭʼ��vector��������ֻ���������״̬�²��ܽ�����һ�ξ�֪��һ������
// ��û�к����������ص�������ʹ��ÿ�������begin�������������

// �ź����ִ�к����㷨������С��x��ʼ���ҵ�һ��������䴩������(��һ������Ӧ�ú�ǰ������Ľ����н���)��
// Ȼ���䴩���ٸ����ҡ�����Ҫִ���ڷ�Ҫһ���䴩�ܶ��ص���������Ϊʣ�µ�������Ҫ��
// �ܶ���ȥ�䣬��˱�֤ÿ�ζ��䴩�������򼴿ɡ�

class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {
		// 1. ����
		class MyCompare
		{
		public:
			bool operator() (vector<int>& v1, vector<int>& v2)const {
				return v1[0] < v2[0];
			}
		};
		sort(points.begin(), points.end(), MyCompare());

		// 2. ��ʼ�������������ص�������Ϊ����v�����index�� ����ʼ����С�ڵ�������v�Ľ������꣬
		// ��˵�����������������ص�����С�ص����䣬�����ж�i+2�����Ƿ���µĿ����ص��������ص���
		// ���жϵ�j���ص����䱬�ص�����count++��v=indexָ�������������䣬��Ϊ�µ��ص�����

		vector<int> v = points[0];
		int count = 0, index = 1;
		int size = points.size();
		while (index < size)
		{
			while (index < size)
			{
				// ��index��ͷС�ڵ�ǰ�����β��˵�����������ཻ
				if (v[1] >= points[index][0])
				{
					// ����Ļ���Ҫ�޸Ľ�����Χ
					v[0] = points[index][0];
					v[1] = v[1] > points[index][1] ? points[index][1] : v[1];
					index++;
				}
				// �����㣬�䱬֮ǰ��������������ʼ�����Ϊindexָ������򣬿�ʼ��һ��ѭ��
				else
				{
					v = points[index];
					index++;
					count++;
					break;
				}
			}
		}
		// ˵���Ǳ�����ĩβ�˳��ģ���һ������û�����䱬��
		count++;
		return count;
	}
};