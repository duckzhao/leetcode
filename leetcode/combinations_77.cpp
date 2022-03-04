#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; i++)
        {
            nums.push_back(i);
        }
        return dfs(nums, k, 0);
    }

    vector<vector<int>> dfs(vector<int>& nums, int k, int begin) {
        vector<vector<int>> retval;
        // ���������һ��ֱ�Ӱ����е�û�б���ǵ������Ž�ȥ
        if (k == 1)
        {
            for (int i = begin; i < nums.size(); i++)
            {
                if (nums[i] != 0)
                {
                    retval.push_back({ nums[i] });
                }
            }
            return retval;
        }

        // �������һ��
        for (int i = begin; i < nums.size(); i++)
        {
            // ��������֮ǰû�б��ù�
            if (nums[i] != 0)
            {
                int temp = nums[i];
                nums[i] = 0;    // ���
                vector<vector<int>> tempv = dfs(nums, k - 1, i + 1);
                for (vector<int> v : tempv)
                {
                    v.push_back(temp);
                    retval.push_back(v);
                }
                nums[i] = temp;     // ��ԭ
            }
        }
        return retval;
    }
};

int main77() {
    Solution s;
    s.combine(4, 2);
    return 0;
}