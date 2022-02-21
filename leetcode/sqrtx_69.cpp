#include<vector>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {

		double left = 0, right = x, middle;
		// 当他们大的，小的，取整为同一个数时，说明这个数就是返回值
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