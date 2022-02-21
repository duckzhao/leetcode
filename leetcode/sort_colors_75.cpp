#include<vector>
#include<unordered_map>
using namespace std;


// ͳ����ɫƵ��ʵ���ϱ���������vector��һ��ͳ�ƣ�һ���޸�
// ���˼��������޹أ��Ǵ� �������ȼ�ժ������
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // ����һ��map���õ����е���ɫ������
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


// ��������ָ��l��r���ֱ�ָ��0��min����2��max���Ľ�������ʼλ�ã�
// ����һ��ָ��i���ڱ����������֣����ܴ�������������������
// nums[i]=0,�򽻻�l��iλ�õ����֣�l++��i++����0�Ǵ���߻�����������iλ�õ���һ����1�����ֱ��i++�������ٴ���֤1���ɣ���
// nums[i]=1,��i++��nums[i]=2���򽻻�r��iλ�õ����֣�r--��i���䣨��Ϊ�����������ֲ�ȷ���Ǽ���Ҫ����֤һ�Σ�
class Solution2
{
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int i = 0;  // i��ߵ����ֿ϶�����0��1
        while (i <= r)
        {
            // �����ǰ����λ��������0�����0�����ļ�¼��λ�ý��н���
            // 0������������һ����0 �� 1��1�Ļ�������ֱ֤������������i++
            if (nums[i] == 0)
            {
                swap(nums, i, l);
                l++;
                i++;
            }
            // �����ǰλ����1����i++��������һ��
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


// �÷��� �ܴ��� �����������(����֪������ʲô����)������
// ����ָ��num1��num2��num3������nums�ֳ���3�������������������δ洢0��1��2�� ����ָ��ֱ�ָ����Է�����β����
// �����ұ�������nums��(1)���nums[i]=0,��1��2��������һ��λ�ã���������0�ڵط��� 
// (2)�����nums[i]=1��ͬ����2������һ��λ�ã���������1�ڵط���ǰ���0����Ӱ�졣
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