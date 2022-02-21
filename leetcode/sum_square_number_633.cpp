#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
	bool judgeSquareSum(int c) {
		//先排除c=0的情况
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
				// 注意：left如果是int类型，则left相关的运算不能超出int类型的取值范围，即四个字节 -2147483648 到 2147483647
				sum = left * left + right * right;
				// 如果平方和小于c
				if (sum < c)
				{
					left++;
				}
				// 如果相等直接break
				else if (sum == c)
				{
					flag = true;
					break;
				}
				// 如果平方和大于c
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