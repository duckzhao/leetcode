#include<vector>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int max_length = 0; // 记录当前匹配的最大长度
        int first_number = 0;   // 记录当前最大长度的第一个字母
        string retval;   // 记录要返回的最长字符串
        string abc = "abcdefghijklmnopqrstuvwxyz";
        string s2;

        int size = dictionary.size();
        // 遍历每一个 字符串，去完成匹配
        for (int i = 0; i < size; i++)
        {
            s2 = dictionary[i];
            int j = 0, k = 0 ;
            // 开始匹配
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
                // 判断是否到达边界
                if (k >= s2.size())
                {
                    // 进行存储值的比较和替换
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
