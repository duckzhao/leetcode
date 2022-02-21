#include<iostream>
#include<string>
using namespace std;

// 回文字符串：正读反读都一样的字符串

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
            // 两头如果相等，继续给中间走
            if ((s[left] == s[right]) && flag)
            {
                left++;
                right--;
            }
            else
            {
                if (left + right == length - 1)
                {
                    // 给左或者右一位可以凑相等
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
                    // 移位无法相等就直接break
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
        // 左边优先删除和右边优先删除都要考虑，防止删除一边以后恰好错过最优解
        // eg:mlcupuufxoo  ooxfuupuc u lm, 删除左c错误，删除右u可以最优解
        left = 0;
        right = length - 1;
        while (left < right)
        {
            // 两头如果相等，继续给中间走
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
                    // 给左或者右一位可以凑相等
                    else if (s[left + 1] == s[right])
                    {
                        left = left + 2;
                        right--;
                    }
                    // 移位无法相等就直接break
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