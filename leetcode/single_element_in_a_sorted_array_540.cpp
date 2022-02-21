#include<vector>
using namespace std;


// 核心在于如何确定下一个迭代区间，即判断middle两侧的数据，那一堆中有single数字
// 考虑到vector的规律，含有single数字的区间一定是奇数，因此以这个为核心取判断即可
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, middle;
        while (left != right)
        {
            middle = left + (right - left) / 2;
            // 给两边找有没有等于middle的元素
            if (nums[middle - 1] == nums[middle])
            {
                // left找到了相同元素，则选择下一个遍历的区间
                if ((middle - 1 - left) % 2 == 0)   // 如果左边是偶数，说明single在右边区间
                {
                    left = middle + 1;
                }
                // 否则single在左边区间
                else
                {
                    right = middle - 2;
                }

            }
            else if (nums[middle] == nums[middle + 1])
            {
                // left找到了相同元素，则选择下一个遍历的区间
                if ((middle - left) % 2 == 0)   // 如果左边是偶数，说明single在右边区间
                {
                    left = middle + 2;
                }
                // 否则single在左边区间
                else
                {
                    right = middle - 1;
                }
            }
            // 如果两边都找不到，则signal就是middle处 的数字
            else
            {
                return nums[middle];
            }
        }
        return nums[left];
    }
};