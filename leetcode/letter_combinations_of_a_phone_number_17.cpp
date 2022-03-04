#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // ���� ���ֺ���ĸ��ӳ�����
        map<char, string> num2str = { {'2', "abc"}, {'3', "def"}, {'4', "ghi"},{'5', "jkl"},{'6', "mno"},{'7', "pqrs"},{'8',"tuv"},{'9', "wxyz"} };
        // ���巵��ֵ
        vector<string> retval;
        // �ų��������
        if (digits.empty())
        {
            return retval;
        }
        // ��ʼ�������
        for (char num : digits)
        {
            backTrack(num2str, retval, num);
        }
        return retval;
    }

    // ��ʼ����
    void backTrack(map<char, string>& num2str, vector<string>& retval, char num) {
        string s2 = num2str[num];
        if (retval.empty())
        {
            for (char c : s2)
            {
                string temp = "";
                retval.push_back(temp+c);
            }
        }
        else
        {
            retval = crossDot(retval, s2);
        }
    }

    // ����vector�������
    vector<string> crossDot(vector<string>& retval, string s2) {
        vector<string> new_retval;
        for (string s1: retval)
        {
            for (char c: s2 )
            {
                new_retval.push_back(s1 + c);
            }
        }
        return new_retval;
    }
};