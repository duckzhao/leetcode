#include<string>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // ������У��洢�������Ľڵ�
        queue<string> q;
        q.push(beginWord);
        // ����Ѿ��������Ľڵ㣬������Ϊ��
        // ����·������
        int count = 1;
        // ��ʼBFS
        while (!q.empty())
        {
            count++;
            int num = q.size();
            while (num--)
            {
                string s1 = q.front();
                q.pop();
                // ����wordlistѰ�������ַ�
                for (int i = 0; i < wordList.size(); i++)
                {
                    string s2 = wordList[i];
                    // �����Ϊ��˵��û������
                    if (s2 != "")
                    {
                        // ���s1��s2����
                        if (judgeNear(s1, s2))
                        {
                            if (s2 == endWord)  // ��������ַ�����end����ֱ��return
                            {
                                return count;
                            }
                            q.push(s2);
                            wordList[i] = "";   // ����Ѿ��������Ľڵ�
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
            }
        }
        return 0;

    }


    // �����Ӻ������ж������ַ����Ƿ�ֻ��һ�� �ַ�
    bool judgeNear(string& s1, string& s2) {
        int change = 0;
        // ����˫ָ�뷽��
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
            {
                change++;
                if (change == 2)
                {
                    return false;
                }
            }
        }
        return true;
    }
};