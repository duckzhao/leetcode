#include<vector>
using namespace std;

// 1. ��nums[i] �� nums[i+1]������ͻʱ���ȿ����޸�i��С��Ҳ�����޸�i+1����
// 2. ����������ѡ�����Ƕ���һ�Σ�copyԭʼ���飬һ��ѭ��ֻ��ǰ������֣�һ��ѭ��ֻ�ĺ��������
// ������һ��ͨ������ͨ����
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int flag1 = 0, flag2 = 0;

        vector<int> nums2 = nums;
        // ɾ����������ַ���
        for (int i = 1; i < nums.size(); i++)
        {
            // ����������ǰ�������С
            if (nums[i] < nums[i - 1])
            {
                // �������������
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

        // ɾ��ǰ���Ԫ��
        for (int i = 1; i < nums2.size(); i++)
        {
            // ����������ǰ�������С
            if (nums2[i] < nums2[i - 1])
            {
                // ����ǰ�������
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


// ����2����ϸ����ʲôʱ��ø�i��ʲôʱ��ø�i+1
// �� i-1 �� i+1��ȣ�i-1С��i+1����˵����i�����ˣ������޸���
// ������� i+1 ̫С�ˣ�ֻ���޸�i+1�ˡ��������߽�����ұ߽磬
// ֱ���޸ı߽�����Ϊ�����ŵ����ּ���
class Solution2 {
public:
    bool checkPossibility(vector<int>& nums) {
        int flag = 0;
        for (int i = 0; i < nums.size() - 1 && flag < 2; i++)
        {
            // ���ǰ��������ں������
            if (nums[i] > nums[i + 1])
            {
                // ���Ǳ߽����
                if (i == 0)
                {
                    nums[i] = nums[i + 1];
                }
                else if (i == nums.size() - 1)
                {
                    nums[i + 1] = nums[i];
                }
                // ��ͨ������ж��ǲ���nums[i+1]̫С��
                else if (nums[i + 1] >= nums[i - 1])
                {
                    nums[i] = nums[i - 1];  // i ̫����
                }
                else
                {
                    nums[i + 1] = nums[i];  // i+1̫С��
                }
                flag++;
            }
        }

        return flag < 2;
    }
};

