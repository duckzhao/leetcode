#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // �� ԭʼ�����������
        sort(candidates.begin(), candidates.end());
        return dfs1(candidates, 0, target);
    }

    vector<vector<int>> dfs1(vector<int>& nums, int begin, int target) {
        // �ж�
        vector<vector<int>> retval;
        if (target == nums[begin])
        {
            return { {nums[begin]} };
        }
        else if (target < nums[begin])
        {
            return retval;
        }

        for (int i = begin; i < nums.size(); i++)
        {
            if (target < nums[i])
            {
                break;
            }
            else if (target == nums[i])
            {
                retval.push_back({ nums[i] });
                break;
            }
            vector<vector<int>> tempv = dfs1(nums, i, target - nums[i]);
            // ���tempv����ֵΪ0��˵�������Ҳ����Ҫ�����ˣ�̫���ˣ��˳�ȥһ��
            if (tempv.size() == 0)
            {
                continue;
            }
            for (auto v : tempv)
            {
                v.push_back(nums[i]);
                retval.push_back(v);
            }
        }
        return retval;
    }
};

int main39() {
    Solution ss;
    vector<int> v = { 2, 3, 6, 7 };
    ss.combinationSum(v, 7);
    return 0;
}