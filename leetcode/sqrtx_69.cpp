#include<vector>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {

		double left = 0, right = x, middle;
		// �����Ǵ�ģ�С�ģ�ȡ��Ϊͬһ����ʱ��˵����������Ƿ���ֵ
		while (int(right) != (int)left)
		{
			middle = left + (right - left) / 2;
			if (middle * middle > x)
			{
				right = middle;
			}
			else if (middle * middle < x)
			{
				left = middle;
			}
			else
			{
				return middle;
			}
		}
		return (int)right;

	}
};