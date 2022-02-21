#include<vector>
using namespace std;

// ���˲���˳������У���СԪ�ص��ص��ǣ�i < i-1
// ˼·�򵥣�ʱ�临�Ӷ�Ϊ O(n)
class Solution {
public:
    int findMin(vector<int>& nums) {
		// �ų�˳������
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

// �����ַ�����left�ƽ����ֵ��right�ƽ���Сֵ
class Solution2 {
public:
	int findMin(vector<int>& nums) {
		// ���ж�û��ѭ�����������
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
				right = middle;	// �ƽ���Сֵ
			}
			else
			{
				left = middle;	// �ƽ����ֵ
			}

		}
		return nums[right];
	}
};