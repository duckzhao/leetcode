#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // 先对nums进行排序, 默认升序
        sort(nums.begin(), nums.end());
        return dfs(nums, 1);
    }
    // 开始dfs
    vector<vector<int>> dfs(vector<int>& nums, int index) {
        vector<vector<int>> retval;
        // 判断
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
        // 循环选择剩下的数
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 100)
            {
                // 标记重复数字
                if (i + 1 < nums.size() && nums[i] == nums[i + 1])
                {
                    visited[i] = true;
                }

                // 去重
                if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1])
                {
                    continue;
                }

                int num = nums[i];
                // 标记为100
                nums[i] = 100;
                vector<vector<int>> temps = dfs(nums, index + 1);
                combine(num, retval, temps);
                nums[i] = num;     // 下一次dfs的时候恢复这个数
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