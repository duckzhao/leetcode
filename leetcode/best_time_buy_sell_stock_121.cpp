#include<vector>
#include<iostream>
using namespace std;


// ���ڸ�����������йأ����������˳���ܸı䣬��˲�������
// ÿ�춼����һ�ι�Ʊ������������˽��׵�����>0���ͱ���������󣬼�������
// С��0���������󣬿�ʼ�´���������¼�������̵�������󣬵�������vector��õ������������ǽ��
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, temp_profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            // �õ��������ν��׵��������
            temp_profit += prices[i] - prices[i - 1];
            if (max_profit < temp_profit)
            {
                max_profit = temp_profit;
            }
            if (temp_profit < 0)
            {
                temp_profit = 0;
            }
        }
        return max_profit;
    }
};

// ��һ��˼·���ҽ�����i����Ϊֹ�ģ���С���������󼴿ɣ�����С���i��һֱ�Ƚϣ�
// ����µĵ��С����֮ǰ�Ͳ��������㣬�������ˣ�����µĵ������õ������������
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0], max_prifit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < min_price)
            {
                min_price = prices[i];
            }
            else
            {
                max_prifit = max_prifit < prices[i] - min_price ? prices[i] - min_price : max_prifit;
            }
        }
        return max_prifit;
    }
};