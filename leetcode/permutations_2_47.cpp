#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // �ȶ�nums��������, Ĭ������
        sort(nums.begin(), nums.end());
        return dfs(nums, 1);
    }
    // ��ʼdfs
    vector<vector<int>> dfs(vector<int>& nums, int index) {
        vector<vector<int>> retval;
        // �ж�
        if (index == nums.size())
        {
            for (int num : nums)
            {
                if (num != 100)
                {
                    retval.push_back({ num });
                    return retval;
                }
            }
        }

        vector<bool> visited(nums.size(), false);
        // ѭ��ѡ��ʣ�µ���
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 100)
            {
                // ����ظ�����
                if (i + 1 < nums.size() && nums[i] == nums[i + 1])
                {
                    visited[i] = true;
                }

                // ȥ��
                if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1])
                {
                    continue;
                }

                int num = nums[i];
                // ���Ϊ100
                nums[i] = 100;
                vector<vector<int>> temps = dfs(nums, index + 1);
                combine(num, retval, temps);
                nums[i] = num;     // ��һ��dfs��ʱ��ָ������
            }
        }
        return retval;
    }

    void combine(int num, vector<vector<int>>& retval, vector<vector<int>>& temps) {
        for (vector<int> temp : temps)
        {
            temp.push_back(num);
            retval.push_back(temp);
        }
    }
};