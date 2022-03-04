#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        vector<vector<int>> retval;
        vector<int> path;   // ��¼ÿһ������·��
        dfs(retval, nums, n, k, path, 0);
        return retval;
    }

    void dfs(vector<vector<int>>& retval, vector<int>& nums, int res, int k, vector<int> path, int left) {
        // �ж�
        if (k == 1)
        {
            // ˵���Ѿ����������ˣ��������εݹ�
            if (res <= 0 || res - 1 > 8 || nums[res - 1] == 0)
                return;
            // �ж��Ƿ񳬳��߽�
            else if (res - 1 >= left)
            {
                path.push_back(res);
                retval.push_back(path);
                return;
            }
        }
        // û����������������dfs
        for (int i = left; i < 9; i++)
        {
            if (nums[i] != 0 && nums[i] <= res)
            {
                // ���
                int temp = nums[i];
                nums[i] = 0;
                path.push_back(temp);
                dfs(retval, nums, res - temp, k - 1, path, i + 1);  // ��һ��ѭ�������i+1��λ�ÿ�ʼ
                // �ָ�
                nums[i] = temp;
                path.pop_back();    // ��path·�������һ������pop��ȥ���ָ�pathԭʼ״̬
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