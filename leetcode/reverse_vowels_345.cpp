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
        // 隔一个开始
        int left = -1;
        int right = length;

        // 判断当前索引是否确认为元音
        bool left_u = false;
        bool right_u = false;

        while (left < right)
        {
            // 如果当前left不是元音字符
            if (left_u == false)
            {
                // 则left++，判断一次
                left++;
                // 不等于 -1 说明当前字符是元音字符
                if (u.find(s[left]) != -1)
                {
                    left_u = true;
                }
            }
            // 如果left是元音字符， 则进一步判断right
            else
            {
                right--;
                // 不等于 -1 说明当前字符是元音字符
                if (u.find(s[right]) != -1)
                {
                    right_u = true;
                    // 交换这两个字符
                    char c;
                    c = s[left];
                    s[left] = s[right];
                    s[right] = c;
                    // 交换完后将flag设置为flase
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