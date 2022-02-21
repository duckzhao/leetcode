#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        // 1. 统计词频
        unordered_map<char, int> char_freq;
        for (int i = 0; i < s.size(); i++)
        {
            char_freq[s[i]]++;
        }

        // 2. 构建 优先级队列，大顶堆问题
		class MyCompare
		{
		public:
            bool operator() (pair<char, int> p1, pair<char, int> p2) const
            {
                return p1.second < p2.second;
            }
		};

        priority_queue<pair<char, int>, vector<pair<char, int>>, MyCompare> pri_queue;

        // 3. 填入元素 char-freq 元素
        for (unordered_map<char, int>::iterator it = char_freq.begin(); it != char_freq.end(); it++)
        {
            pri_queue.push(*it);    // 插入时，priority_queue内部会自动按照 每个char的freq进行升序排列
        }

        // 4. 生成结果
        string retval = "";
        while (pri_queue.size())    // 当size不为0就一直循环，直至所有元素都弹出，不能用i++这种，因为无法随机访问queue中的元素
        {
            pair<char, int> temp_pair = pri_queue.top();
            pri_queue.pop();
            char temp_char = temp_pair.first;
            int temp_freq = temp_pair.second;
            retval.append(string(temp_freq, temp_char));
        }
        return retval;
    }
};