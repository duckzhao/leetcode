#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        vector<vector<int>> retval;
        vector<int> path;   // 记录每一个迭代路径
        dfs(retval, nums, n, k, path, 0);
        return retval;
    }

    void dfs(vector<vector<int>>& retval, vector<int>& nums, int res, int k, vector<int> path, int left) {
        // 判断
        if (k == 1)
        {
            // 说明已经被遍历过了，跳出本次递归
            if (res <= 0 || res - 1 > 8 || nums[res - 1] == 0)
                return;
            // 判断是否超出边界
            else if (res - 1 >= left)
            {
                path.push_back(res);
                retval.push_back(path);
                return;
            }
        }
        // 没到跳出条件，继续dfs
        for (int i = left; i < 9; i++)
        {
            if (nums[i] != 0 && nums[i] <= res)
            {
                // 标记
                int temp = nums[i];
                nums[i] = 0;
                path.push_back(temp);
                dfs(retval, nums, res - temp, k - 1, path, i + 1);  // 下一次循环必须从i+1的位置开始
                // 恢复
                nums[i] = temp;
                path.pop_back();    // 将path路径的最后一个数，pop出去，恢复path原始状态
            }
        }
    }
};

int main216()
{
    Solution s;
    s.combinationSum3(2, 18);
    return 0;
}