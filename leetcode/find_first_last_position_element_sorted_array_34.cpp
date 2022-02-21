#include<iostream>
#include<vector>
using namespace std;


/*
�����ǣ����������ʣ���������������ѭ���Ļ���������left + 1 < right
��Ϊwhileѭ�����˳�������Ȼ���ֶ���ʣ��������������жϼ��ɡ�
���������߼���һЩ������Ҫ��д�ܶิ�Ӵ��룬����������ķ�����
��סһ��׼�򣬽���[2��3]��ѭ����Զ����Ϊleft��middle����С�����ϣ�
��˱�֤ letf=middle+1 ����������ɡ�����ʲôʱ�����left�Լ��ж�
*/


// �����ζ��ַ���һ������߽��target��һ�����ұ߽��target��leftһֱ����middle+1
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v = { -1, -1 };
        // �ų�numsΪ����������
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
                left = middle + 1;  // left��Ҫ+1��ֹ�����ѭ����middleһֱ����
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

        // ��ʼ�����ұ߽磬����right
        right = nums.size() - 1;
        while (left < right)
        {
            middle = left + (right - left) / 2;
            if (nums[middle] <= target)
            {
                left = middle + 1;  // ��֤leftһֱ���ڵ���״̬����ֹ����[2,3] ��ѭ��,
                                    // ������ʹ���Ľ���ƽ�����target�ĵ�һ������
            }
            else
            {
                right = middle;
            }
        }
        // ��Ϊ�ҵĽ���Ǵ���target�ĵ�һ�����֣����target�ı߽���right-1��λ��
        // ���������������target����Ϊ���Ҳ��ֵ������leftһֱ������ƽ�right�˳�ѭ��
        // ������ж����Ҳ��ֵ�ǲ���target
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