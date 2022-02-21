#include<iostream>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        string u = "aeiouAEIOU";
        int length = s.length();
        // ��һ����ʼ
        int left = -1;
        int right = length;

        // �жϵ�ǰ�����Ƿ�ȷ��ΪԪ��
        bool left_u = false;
        bool right_u = false;

        while (left < right)
        {
            // �����ǰleft����Ԫ���ַ�
            if (left_u == false)
            {
                // ��left++���ж�һ��
                left++;
                // ������ -1 ˵����ǰ�ַ���Ԫ���ַ�
                if (u.find(s[left]) != -1)
                {
                    left_u = true;
                }
            }
            // ���left��Ԫ���ַ��� ���һ���ж�right
            else
            {
                right--;
                // ������ -1 ˵����ǰ�ַ���Ԫ���ַ�
                if (u.find(s[right]) != -1)
                {
                    right_u = true;
                    // �����������ַ�
                    char c;
                    c = s[left];
                    s[left] = s[right];
                    s[right] = c;
                    // �������flag����Ϊflase
                    left_u = false;
                    right_u = false;
                }
            }

        }
        return s;
    }
};

int main345() {
    Solution S;
    string s = S.reverseVowels("leetcode");
    cout << s << endl;
    return 0;
}