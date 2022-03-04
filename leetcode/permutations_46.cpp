#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
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
                }
            }
        }
        // 循环选择剩下的数
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 100)
            {
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