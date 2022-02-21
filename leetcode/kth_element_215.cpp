#include<vector>
#include<iostream>
#include<algorithm> // 打乱数组顺序，防止极端情况快排时间复杂度 O(NlogN) 退化到o(N2)
#include <random>       // std::default_random_engine
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 对原始数组乱序
        shuffle(nums.begin(), nums.end(), default_random_engine(random_device()()));

        // 使用快速排序法
        quickSort(nums, 0, nums.size() - 1);
        return nums[nums.size() - k];

    }

    // 快排核心思想：找一个基准数（挖一个坑），从两头开始一边找大的，一边找小的，直到碰头位置，
    // 把基准数填进去，则以这个位置为界限，左边小于基准数，右边大于基准数
    // 定义函数 quick_sort(vector<int>& nums, int left, int right)
    // 1. 以最左边的数作为基准，i=left, j=right, X=nums[left]
    // 2. while从右边给左找，即j--，直到找一个小于等于X的数；nums[i] = nums[j]; i++;
    // 3. while从左边给右找，即i++，直到找一个大于等于X的数；num[j] = nums[i]; j--;
    // 重复以上，直到 i>=j，说明i和j指到同一个格子，将X放入这个格子，nums[i]=X; 这次迭代结束
    // 对子集【left, i-1】和子集【j+1, right】继续使用quick_sort函数
    void quickSort(vector<int>& nums, int left, int right) {

        // 递归的退出条件是：left 不小于 right，说明只有一个数了，不用排了
        // 只能用不小于不能用 ！= 判断是因为 left有可能 等于i，right=j，
        // 这种情况下 quickSort(nums, left, i - 1); quickSort(nums, i + 1, right); 就会不相等
        // 最后i-1变为负数，内存访问错误
        if (left < right)
        {
            int i = left;
            int j = right;
            int X = nums[left];
            // 开始循环从两头给中间靠
            while (i < j)
            {
                // 先从右边给左找小于X的数
                while (i < j && nums[j] >= X)
                {
                    j--;
                }
                // 只有当都找到时才能换，相遇不能换，因为换了i++位置会移动
                // 找到后和i交换
                if (i < j)
                {
                    nums[i] = nums[j];
                    i++;
                }

                // 然后从左给右找大于X的数
                while (i < j && nums[i] <= X)
                {
                    i++;
                }
                // 只有当都找到时才能换，相遇不能换，因为换了j--位置会移动
                // 找到后和j交换
                if (i < j)
                {
                    nums[j] = nums[i];
                    j--;
                }

            }
            // 循环跳出说明 i==j，交换X和i/j
            nums[i] = X;

            // 对基准数左边（小），右边（大）的数，递归调用该函数
            quickSort(nums, left, i - 1);
            quickSort(nums, i + 1, right);
        }
    }
};

void main215() {
    Solution s;
    vector<int> v = { 3,2,1,5,6,4 };
    s.findKthLargest(v, 2);
    return;
}