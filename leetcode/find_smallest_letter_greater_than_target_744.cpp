#include<string>
#include<vector>
using namespace std;


class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // ��Ϊ��ѭ��ѡ�������ȿ������ּ����������ȫ����target��
        // ��letters[0]>target��return letters[0]
        // ȫ���� targetС����letters[-1]<target��return letters[0]
        if (letters[0] > target || letters.back() <= target)
        {
            return letters[0];
        }

        // ���ַ�ʹ��whileѭ����������left��right����right��left���벻��1ʱ��
        // ���˳�ѭ�����ֶ��ж�left��right�ĸ�����Ҫ������
        int left = 0, right = letters.size() - 1, middle;
        while (right - left > 1)
        {
            middle = left + (right - left) / 2;
            if (letters[middle] > target)
            {
                right = middle;
            }
            else
            {
                left = middle;
            }
        }
        
        return letters[right];
    }
};