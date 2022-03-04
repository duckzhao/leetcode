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
        // �ж�
        if (s1.size() == 1)
        {
            path.push_back(s1);
            retval.push_back(path);
            return;
        }

        // ���s1�ĳ��Ȳ�Ϊ1��������ָ�ָ���ж�ǰ��Ĵ��ǲ��ǻ��Ĵ�
        // i��ʾ�ָ�λ��
        for (int i = 1; i <= s1.size(); i++)
        {
            // ��ȡǰ����ַ���
            string s2 = s1.substr(0, i);
            // i=s1.size()ʱ��s2ȡ���������ַ�����s3��ȡ��Խ�磬���ȡ���˵����Ҫ�ж��£����ٴ�dfs�ˣ�ֱ���ж�s2���Ĳ������ؼ���
            if (i == s1.size() && judgeCycle(s2))
            {
                path.push_back(s2);
                retval.push_back(path);
                return;
            }
            // �ж�s2�Ƿ�Ϊ���Ĵ�
            else if (judgeCycle(s2))
            {
                path.push_back(s2);
                string s3 = s1.substr(i);
                dfs(s3, path, retval);
                path.pop_back();
            }
        }
    }
    // �ж��Ƿ��ǻ����ַ���
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