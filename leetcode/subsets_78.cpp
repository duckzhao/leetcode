#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> retval;
		retval.push_back({});

		// ��¼·��
		vector<int> path;
		for (int i = 1; i <= nums.size(); i++)
		{
			dfs(retval, nums, i, path, 0);
		}
		return retval;
    }

	void dfs(vector<vector<int>>& retval, vector<int>& nums, int k, vector<int> path, int left) {
		// �ж�
		if (k == 1)
		{
			for (int i = left; i < nums.size(); i++)
			{
				path.push_back(nums[i]);
				retval.push_back(path);
				path.pop_back();
			}
		}

		// ��������
		for (int i = left; i < nums.size(); i++)
		{
			// �ж�ʣ�µ���������������
			if (k > nums.size() - i)
			{
				break;
			}
			path.push_back(nums[i]);
			dfs(retval, nums, k - 1, path, i + 1);
			path.pop_back();
		}
	}
};