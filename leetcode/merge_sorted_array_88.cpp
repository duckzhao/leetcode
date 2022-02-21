#include<iostream>
#include<vector>
using namespace std;


// 双指针从后给前遍历，且设置一个控制在 输出vector 上定位的 n+m-1 的索引 作为循环条件很关键

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // 先排除vector可能为空的情况
        if (m == 0)
        {
            nums1 = nums2;
            return;
        }
        else if(n == 0)
        {
            return;
        }
        else
        {
            // 开始写逻辑
            int i = m - 1, j = n - 1;
            // 从两个vector的后给前遍历
            for (int k = n + m - 1; k >= 0; k--)
            {
                // 如果nums2最后一个都遍历了，直接return
                if (j < 0)
                {
                    break;
                }

                // 如果nums1最后一个已经遍历了
                    // 把nums2从后給前赋值给nums1即可
                if (i < 0)
                {
                    while (k >= 0)
                    {
                        nums1[k] = nums2[j];
                        j--;
                        k--;
                    }
                    break;
                }

                if (nums1[i] <= nums2[j])
                {
                    nums1[k] = nums2[j];
                    j--;
                }
                else
                {
                    nums1[k] = nums1[i];
                    i--;
                }
            }

        }
    }
};

int main88() {

    Solution s;
    vector<int> v1 = { 2,0 };
    vector<int> v2 = { 1 };
    s.merge(v1, 1, v2, 1);
    return 0;
}