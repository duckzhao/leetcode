#include<vector>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int max_length = 0; // ��¼��ǰƥ�����󳤶�
        int first_number = 0;   // ��¼��ǰ��󳤶ȵĵ�һ����ĸ
        string retval;   // ��¼Ҫ���ص���ַ���
        string abc = "abcdefghijklmnopqrstuvwxyz";
        string s2;

        int size = dictionary.size();
        // ����ÿһ�� �ַ�����ȥ���ƥ��
        for (int i = 0; i < size; i++)
        {
            s2 = dictionary[i];
            int j = 0, k = 0 ;
            // ��ʼƥ��
            while (true)
            {
                if (s[j] == s2[k])
                {
                    j++;
                    k++;
                }
                else
                {
                    j++;
                }
                // �ж��Ƿ񵽴�߽�
                if (k >= s2.size())
                {
                    // ���д洢ֵ�ıȽϺ��滻
                    if (max_length < s2.size())
                    {
                        max_length = s2.size();
                        first_number = s2[0];
                        retval = s2;
                    }
                    else if ((max_length == s2.size()) && (s2.compare(retval) < 0))
                    {
                        max_length = s2.size();
                        first_number = s2[0];
                        retval = s2;
                    }
                    break;
                }
                if (j >= s.size())
                {
                    break;
                }

            }
        }
        return retval;
    }
};

int main524() {
    string s1 = "acv";
    cout << s1[0] << endl;

    return 0;
}
