#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        // 1. ͳ�ƴ�Ƶ
        unordered_map<char, int> char_freq;
        for (int i = 0; i < s.size(); i++)
        {
            char_freq[s[i]]++;
        }

        // 2. ���� ���ȼ����У��󶥶�����
		class MyCompare
		{
		public:
            bool operator() (pair<char, int> p1, pair<char, int> p2) const
            {
                return p1.second < p2.second;
            }
		};

        priority_queue<pair<char, int>, vector<pair<char, int>>, MyCompare> pri_queue;

        // 3. ����Ԫ�� char-freq Ԫ��
        for (unordered_map<char, int>::iterator it = char_freq.begin(); it != char_freq.end(); it++)
        {
            pri_queue.push(*it);    // ����ʱ��priority_queue�ڲ����Զ����� ÿ��char��freq������������
        }

        // 4. ���ɽ��
        string retval = "";
        while (pri_queue.size())    // ��size��Ϊ0��һֱѭ����ֱ������Ԫ�ض�������������i++���֣���Ϊ�޷��������queue�е�Ԫ��
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