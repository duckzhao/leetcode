#include<iostream>
#include<vector>
using namespace std;


// ˫ָ��Ӻ��ǰ������������һ�������� ���vector �϶�λ�� n+m-1 ������ ��Ϊѭ�������ܹؼ�

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // ���ų�vector����Ϊ�յ����
        if (m == 0)
        {
            nums1 = nums2;
            return;
        }
        else if(n == 0)
        {
            return;
        }
        else
        {
            // ��ʼд�߼�
            int i = m - 1, j = n - 1;
            // ������vector�ĺ��ǰ����
            for (int k = n + m - 1; k >= 0; k--)
            {
                // ���nums2���һ���������ˣ�ֱ��return
                if (j < 0)
                {
                    break;
                }

                // ���nums1���һ���Ѿ�������
                    // ��nums2�Ӻ�oǰ��ֵ��nums1����
                if (i < 0)
                {
                    while (k >= 0)
                    {
                        nums1[k] = nums2[j];
                        j--;
                        k--;
                    }
                    break;
                }

                if (nums1[i] <= nums2[j])
                {
                    nums1[k] = nums2[j];
                    j--;
                }
                else
                {
                    nums1[k] = nums1[i];
                    i--;
                }
            }

        }
    }
};

int main88() {

    Solution s;
    vector<int> v1 = { 2,0 };
    vector<int> v2 = { 1 };
    s.merge(v1, 1, v2, 1);
    return 0;
}