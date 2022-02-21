#include<vector>
#include<iostream>
#include<algorithm> // ��������˳�򣬷�ֹ�����������ʱ�临�Ӷ� O(NlogN) �˻���o(N2)
#include <random>       // std::default_random_engine
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // ��ԭʼ��������
        shuffle(nums.begin(), nums.end(), default_random_engine(random_device()()));

        // ʹ�ÿ�������
        quickSort(nums, 0, nums.size() - 1);
        return nums[nums.size() - k];

    }

    // ���ź���˼�룺��һ����׼������һ���ӣ�������ͷ��ʼһ���Ҵ�ģ�һ����С�ģ�ֱ����ͷλ�ã�
    // �ѻ�׼�����ȥ���������λ��Ϊ���ޣ����С�ڻ�׼�����ұߴ��ڻ�׼��
    // ���庯�� quick_sort(vector<int>& nums, int left, int right)
    // 1. ������ߵ�����Ϊ��׼��i=left, j=right, X=nums[left]
    // 2. while���ұ߸����ң���j--��ֱ����һ��С�ڵ���X������nums[i] = nums[j]; i++;
    // 3. while����߸����ң���i++��ֱ����һ�����ڵ���X������num[j] = nums[i]; j--;
    // �ظ����ϣ�ֱ�� i>=j��˵��i��jָ��ͬһ�����ӣ���X����������ӣ�nums[i]=X; ��ε�������
    // ���Ӽ���left, i-1�����Ӽ���j+1, right������ʹ��quick_sort����
    void quickSort(vector<int>& nums, int left, int right) {

        // �ݹ���˳������ǣ�left ��С�� right��˵��ֻ��һ�����ˣ���������
        // ֻ���ò�С�ڲ����� ��= �ж�����Ϊ left�п��� ����i��right=j��
        // ��������� quickSort(nums, left, i - 1); quickSort(nums, i + 1, right); �ͻ᲻���
        // ���i-1��Ϊ�������ڴ���ʴ���
        if (left < right)
        {
            int i = left;
            int j = right;
            int X = nums[left];
            // ��ʼѭ������ͷ���м俿
            while (i < j)
            {
                // �ȴ��ұ߸�����С��X����
                while (i < j && nums[j] >= X)
                {
                    j--;
                }
                // ֻ�е����ҵ�ʱ���ܻ����������ܻ�����Ϊ����i++λ�û��ƶ�
                // �ҵ����i����
                if (i < j)
                {
                    nums[i] = nums[j];
                    i++;
                }

                // Ȼ���������Ҵ���X����
                while (i < j && nums[i] <= X)
                {
                    i++;
                }
                // ֻ�е����ҵ�ʱ���ܻ����������ܻ�����Ϊ����j--λ�û��ƶ�
                // �ҵ����j����
                if (i < j)
                {
                    nums[j] = nums[i];
                    j--;
                }

            }
            // ѭ������˵�� i==j������X��i/j
            nums[i] = X;

            // �Ի�׼����ߣ�С�����ұߣ��󣩵������ݹ���øú���
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