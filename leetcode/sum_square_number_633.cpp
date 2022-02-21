#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
	bool judgeSquareSum(int c) {
		//���ų�c=0�����
		if (c == 0)
		{
			return true;
		}
		else
		{
			long int left = 0;
			long int right = (int)sqrt(c);

			long int sum;

			bool flag = false;
			while (left <= right)
			{	
				// ע�⣺left�����int���ͣ���left��ص����㲻�ܳ���int���͵�ȡֵ��Χ�����ĸ��ֽ� -2147483648 �� 2147483647
				sum = left * left + right * right;
				// ���ƽ����С��c
				if (sum < c)
				{
					left++;
				}
				// ������ֱ��break
				else if (sum == c)
				{
					flag = true;
					break;
				}
				// ���ƽ���ʹ���c
				else
				{
					right--;
				}
			}
			return flag;
		}

	}
};


int main633() {

	return 0;
}