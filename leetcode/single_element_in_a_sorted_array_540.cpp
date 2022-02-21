#include<vector>
using namespace std;


// �����������ȷ����һ���������䣬���ж�middle��������ݣ���һ������single����
// ���ǵ�vector�Ĺ��ɣ�����single���ֵ�����һ������������������Ϊ����ȡ�жϼ���
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, middle;
        while (left != right)
        {
            middle = left + (right - left) / 2;
            // ����������û�е���middle��Ԫ��
            if (nums[middle - 1] == nums[middle])
            {
                // left�ҵ�����ͬԪ�أ���ѡ����һ������������
                if ((middle - 1 - left) % 2 == 0)   // ��������ż����˵��single���ұ�����
                {
                    left = middle + 1;
                }
                // ����single���������
                else
                {
                    right = middle - 2;
                }

            }
            else if (nums[middle] == nums[middle + 1])
            {
                // left�ҵ�����ͬԪ�أ���ѡ����һ������������
                if ((middle - left) % 2 == 0)   // ��������ż����˵��single���ұ�����
                {
                    left = middle + 2;
                }
                // ����single���������
                else
                {
                    right = middle - 1;
                }
            }
            // ������߶��Ҳ�������signal����middle�� ������
            else
            {
                return nums[middle];
            }
        }
        return nums[left];
    }
};