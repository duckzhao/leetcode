#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

// ̰��˼�룬��������������ٱ��ɵ��������Ϊ������һ��������С��
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // �ȶ����к��ӵ�θ�ںͱ��ɴ�С��������-����
        // ����С��θ��i�ͱ���j��ʼ�Ƚϣ������ɴ�С���㺢��θ��ʱ��i++��j++
        // ���� j++��ֱ�� i �� j����sizeΪֹ
        sort(g.begin(), g.end());   // sortĬ������
        sort(s.begin(), s.end());
        int i = 0, j = 0, count = 0;
        while ((i < g.size()) && (j < s.size()))
        {
            // ������θ�������㣬��++
            if (g[i] <= s[j])
            {
                count++;
                i++;
                j++;
            }
            // ������һ�����ı�������
            else
            {
                j++;
            }
        }
        return count;
    }
};