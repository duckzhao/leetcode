#include<vector>
using namespace std;

// 1. 当nums[i] 和 nums[i+1]发生冲突时，既可以修改i更小，也可以修改i+1更大
// 2. 所以这两种选择，我们都做一次，copy原始数组，一个循环只改前面的数字，一个循环只改后面的数字
// 两个有一个通过就算通过。
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int flag1 = 0, flag2 = 0;

        vector<int> nums2 = nums;
        // 删除后面的数字方案
        for (int i = 1; i < nums.size(); i++)
        {
            // 后面的如果比前面的数字小
            if (nums[i] < nums[i - 1])
            {
                // 擦除后面的数字
                nums.erase(nums.begin() + i);
                i--;
                flag1++;
                if (flag1 == 2)
                {
                    break;
                }
            }
        }
        if (flag1 < 2)
        {
            return true;
        }

        // 删除前面的元素
        for (int i = 1; i < nums2.size(); i++)
        {
            // 后面的如果比前面的数字小
            if (nums2[i] < nums2[i - 1])
            {
                // 擦除前面的数字
                nums2.erase(nums2.begin() + i - 1);
                i -= 2;
                if (i < 0)
                {
                    i = 0;
                }
                flag2++;
                if (flag2 == 2)
                {
                    break;
                }
            }
        }
        return flag2 < 2;
    }
};


// 方案2，仔细考虑什么时候该改i，什么时候该改i+1
// 当 i-1 和 i+1相比，i-1小于i+1，那说明是i过大了，我们修改它
// 否则就是 i+1 太小了，只能修改i+1了。如果是左边界或者右边界，
// 直接修改边界数字为紧邻着的数字即可
class Solution2 {
public:
    bool checkPossibility(vector<int>& nums) {
        int flag = 0;
        for (int i = 0; i < nums.size() - 1 && flag < 2; i++)
        {
            // 如果前面的数大于后面的数
            if (nums[i] > nums[i + 1])
            {
                // 考虑边界情况
                if (i == 0)
                {
                    nums[i] = nums[i + 1];
                }
                else if (i == nums.size() - 1)
                {
                    nums[i + 1] = nums[i];
                }
                // 普通情况，判断是不是nums[i+1]太小了
                else if (nums[i + 1] >= nums[i - 1])
                {
                    nums[i] = nums[i - 1];  // i 太大了
                }
                else
                {
                    nums[i + 1] = nums[i];  // i+1太小了
                }
                flag++;
            }
        }

        return flag < 2;
    }
};

