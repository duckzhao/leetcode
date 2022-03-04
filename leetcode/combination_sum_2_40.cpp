#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> r=  dfs3(candidates, 0, target);
        return r;
    }

    vector<vector<int>> dfs3(vector<int>& nums, int begin, int target) {
        vector<vector<int>> retval;
        if (nums[begin] == target)
        {
            return { {target} };
        }
        else if (nums[begin] > target)
        {
            return retval;
        }

        // 去重
        vector<int> visited(nums.size(), 0);

        // 说明之前所有的数之和 , 加上[begin]还不够
        for (int i = begin; i < nums.size(); i++)
        {
            visited[i] = 1; // 去重
            if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1])
            {
                continue;
            }

            if (nums[i] == target)
            {
                retval.push_back({ target });
            }

            if (i + 1 >= nums.size())
            {
                return retval;
            }
            vector<vector<int>> tempv = dfs3(nums, i + 1, target - nums[i]);
            if (tempv.size() == 0)
            {
                continue;
            }
            else
            {
                for (auto v : tempv)
                {
                    v.push_back(nums[i]);
                    retval.push_back(v);
                }
            }
        }
        return retval;
    }
};

int main40() {
    vector<int> v = { 10,1,2,7,6,1,5 };
    Solution s;
    s.combinationSum2(v, 8);
    return 0;
}