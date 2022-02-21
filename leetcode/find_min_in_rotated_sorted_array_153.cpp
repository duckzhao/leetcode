#include<vector>
using namespace std;

// 除了不变顺序的数列，最小元素的特点是：i < i-1
// 思路简单，时间复杂度为 O(n)
class Solution {
public:
    int findMin(vector<int>& nums) {
		// 排除顺序数列
		if (nums[0] <= nums.back())
		{
			return nums[0];
		}

		int retval = 0;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] < nums[i - 1])
			{
				retval = nums[i];
				break;
			}
		}
		return retval;
    }
};

// 换二分法做，left逼近最大值，right逼近最小值
class Solution2 {
public:
	int findMin(vector<int>& nums) {
		// 先判断没有循环的特殊情况
		if (nums[0] <= nums.back())
		{
			return nums[0];
		}

		int left = 0, right = nums.size() - 1, middle;
		while (left + 1 != right)
		{
			middle = left + (right - left) / 2;
			if (nums[middle] < nums[left])
			{
				right = middle;	// 逼近最小值
			}
			else
			{
				left = middle;	// 逼近最大值
			}

		}
		return nums[right];
	}
};