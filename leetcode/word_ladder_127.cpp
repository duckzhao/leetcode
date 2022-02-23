#include<string>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 定义队列，存储待遍历的节点
        queue<string> q;
        q.push(beginWord);
        // 标记已经遍历过的节点，将它变为空
        // 定义路径长度
        int count = 1;
        // 开始BFS
        while (!q.empty())
        {
            count++;
            int num = q.size();
            while (num--)
            {
                string s1 = q.front();
                q.pop();
                // 遍历wordlist寻找相邻字符
                for (int i = 0; i < wordList.size(); i++)
                {
                    string s2 = wordList[i];
                    // 如果不为空说明没遍历过
                    if (s2 != "")
                    {
                        // 如果s1和s2相邻
                        if (judgeNear(s1, s2))
                        {
                            if (s2 == endWord)  // 如果相邻字符串是end，则直接return
                            {
                                return count;
                            }
                            q.push(s2);
                            wordList[i] = "";   // 标记已经遍历过的节点
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


    // 定义子函数，判断两个字符串是否只差一个 字符
    bool judgeNear(string& s1, string& s2) {
        int change = 0;
        // 采用双指针方法
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