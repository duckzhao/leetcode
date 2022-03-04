#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> retval;
        vector<string> path;
        dfs(s, path, retval);
        return retval;
    }

    void dfs(string& s1, vector<string> path, vector<vector<string>>& retval) {
        // 判断
        if (s1.size() == 1)
        {
            path.push_back(s1);
            retval.push_back(path);
            return;
        }

        // 如果s1的长度不为1，则继续分割，分割后判断前面的串是不是回文串
        // i表示分割位置
        for (int i = 1; i <= s1.size(); i++)
        {
            // 截取前面的字符串
            string s2 = s1.substr(0, i);
            // i=s1.size()时，s2取完了所有字符串，s3再取会越界，因此取完了的情况要判断下，不再次dfs了，直接判断s2回文不，返回即可
            if (i == s1.size() && judgeCycle(s2))
            {
                path.push_back(s2);
                retval.push_back(path);
                return;
            }
            // 判断s2是否为回文串
            else if (judgeCycle(s2))
            {
                path.push_back(s2);
                string s3 = s1.substr(i);
                dfs(s3, path, retval);
                path.pop_back();
            }
        }
    }
    // 判断是否是回文字符串
    bool judgeCycle(string& s2) {
        if (s2.size() == 1)
        {
            return true;
        }
        else
        {
            int l = 0, r = s2.size() - 1;
            while (l<r)
            {
                if (s2[l] != s2[r])
                {
                    return false;
                }
                l++;
                r--;
            }
        }
        return true;
    }
};