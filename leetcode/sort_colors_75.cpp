#include<vector>
#include<unordered_map>
using namespace std;


// 统计颜色频率实际上遍历了两次vector，一次统计，一次修改
// 这个思想和排序无关，是从 队列优先级摘出来的
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 定义一个map，拿到所有的颜色的数量
        unordered_map<int, int> colors_freq;
        for (auto num: nums)
        {
            colors_freq[num]++;
        }
        int index = 0;
        for (int color = 0; color < 3; color++)
        {
            for (int j = 0; j < colors_freq[color]; j++)
            {
                nums[index++] = color;
            }
        }

    }
};


// 设置两个指针l，r，分别指向0（min）和2（max）的结束和起始位置，
// 还有一个指针i用于遍历所有数字，仅能处理三个数字排序的情况
// nums[i]=0,则交换l和i位置的数字，l++，i++（换0是从左边换过来，过来i位置的数一定是1，因此直接i++，跳过再次验证1即可）；
// nums[i]=1,则i++；nums[i]=2，则交换r和i位置的数字，r--，i不变（因为换过来的数字不确定是几还要再验证一次）
class Solution2
{
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int i = 0;  // i左边的数字肯定都是0或1
        while (i <= r)
        {
            // 如果当前遍历位置数字是0，则和0索引的记录点位置进行交换
            // 0换过来的数字一定是0 或 1，1的话不用验证直接跳过，所以i++
            if (nums[i] == 0)
            {
                swap(nums, i, l);
                l++;
                i++;
            }
            // 如果当前位置是1，则i++，遍历下一轮
            else if (nums[i] == 1)
            {
                i++;
            }
            else
            {
                swap(nums, i, r);
                r--;
            }
        }
    }

    void swap(vector<int>& nums, int i, int j) {
        if (i == j)
        {
            return;
        }
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};


// 该方法 能处理 多个有限数字(事先知道都有什么数字)的排序
// 三个指针num1、num2、num3将数组nums分成了3个分区，从左往右依次存储0、1、2。 三个指针分别指向各自分区的尾部。
// 从左到右遍历数组nums，(1)如果nums[i]=0,则1、2区都后移一个位置，给新来的0腾地方。 
// (2)如果是nums[i]=1，同样，2区后移一个位置，给新来的1腾地方。前面的0区无影响。
class Solution3 {
public:
    void sortColors(vector<int>& nums) {
        int num0 = 0, num1 = 0, num2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                nums[num2++] = 2;
                nums[num1++] = 1;
                nums[num0++] = 0;
            }
            else if (nums[i] == 1) {
                nums[num2++] = 2;
                nums[num1++] = 1;
            }
            else {
                nums[num2++] = 2;
            }
        }
    }
};

void main75() {
    Solution2 s2;
    vector<int> v = { 2,0,2,1,1,0 };
    s2.sortColors(v);
}