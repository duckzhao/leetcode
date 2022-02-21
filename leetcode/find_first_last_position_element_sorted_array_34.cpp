#include<iostream>
#include<vector>
using namespace std;


/*
核心是！！！如果怕剩最后两个数陷入死循环的话，可以用left + 1 < right
作为while循环的退出条件，然后手动对剩余的两个数坐下判断即可。
如果上面的逻辑在一些场景下要多写很多复杂代码，可以用下面的方法，
记住一个准则，进入[2，3]死循环永远是因为left和middle卡在小数字上，
因此保证 letf=middle+1 这个条件即可。至于什么时候进入left自己判断
*/


// 用两次二分法，一次找左边界的target，一次找右边界的target，left一直等于middle+1
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v = { -1, -1 };
        // 排除nums为空数组的情况
        if (nums.empty())
        {
            return v;
        }

        int left = 0, right = nums.size() - 1, middle;
        while (left < right)
        {
            middle = left + (right - left) / 2;
            if (nums[middle] < target)
            {
                left = middle + 1;  // left需要+1防止变成死循环，middle一直不变
            }
            else
            {
                right = middle;
            }
        }
        if (nums[left] != target)
        {
            return v;
        }
        v[0] = left;

        // 开始遍历右边界，重设right
        right = nums.size() - 1;
        while (left < right)
        {
            middle = left + (right - left) / 2;
            if (nums[middle] <= target)
            {
                left = middle + 1;  // 保证left一直处于递增状态，防止陷入[2,3] 死循环,
                                    // 这样会使最后的结果逼近大于target的第一个数字
            }
            else
            {
                right = middle;
            }
        }
        // 因为找的结果是大于target的第一个数字，因此target的边界在right-1的位置
        // 但考虑特殊情况，target可能为最右侧的值，导致left一直不满足逼近right退出循环
        // 因此先判断最右侧的值是不是target
        if (nums.back() != target)
        {
            v[1] = right - 1;
        }
        else
        {
            v[1] = right;
        }
        return v;
    }
};