#include<iostream>
#include<string>
using namespace std;

// �����ַ���������������һ�����ַ���

class Solution {
public:
    bool validPalindrome(string s) {
        int length = s.size();
        int left = 0;
        int right = length - 1;
        bool flag = true;
        bool flag2 = true;
        while (left < right)
        {
            // ��ͷ�����ȣ��������м���
            if ((s[left] == s[right]) && flag)
            {
                left++;
                right--;
            }
            else
            {
                if (left + right == length - 1)
                {
                    // ���������һλ���Դ����
                    if (s[left + 1] == s[right])
                    {
                        left = left + 2;
                        right--;
                    }
                    else if (s[left] == s[right - 1])
                    {
                        right = right - 2;
                        left++;
                    }
                    // ��λ�޷���Ⱦ�ֱ��break
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                else
                {
                    flag = false;
                    break;
                }
                
            }
        }
        // �������ɾ�����ұ�����ɾ����Ҫ���ǣ���ֹɾ��һ���Ժ�ǡ�ô�����Ž�
        // eg:mlcupuufxoo  ooxfuupuc u lm, ɾ����c����ɾ����u�������Ž�
        left = 0;
        right = length - 1;
        while (left < right)
        {
            // ��ͷ�����ȣ��������м���
            if ((s[left] == s[right]) && flag2)
            {
                left++;
                right--;
            }
            else
            {
                if (left + right == length - 1)
                {
                    if (s[left] == s[right - 1])
                    {
                        right = right - 2;
                        left++;
                    }
                    // ���������һλ���Դ����
                    else if (s[left + 1] == s[right])
                    {
                        left = left + 2;
                        right--;
                    }
                    // ��λ�޷���Ⱦ�ֱ��break
                    else
                    {
                        flag2 = false;
                        break;
                    }
                }
                else
                {
                    flag2 = false;
                    break;
                }

            }
        }
        bool b = flag || flag2;
        cout << b << endl;
        return b;
    }
};

int main680() {

    Solution S;
    S.validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga");
    return 0;
}