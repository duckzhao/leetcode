#include<vector>
using namespace std;

// �������������ƣ����ǲ�������
// ÿ�������춼����һ�β�����������׽��Ϊ+���ͼ���profit�У�
// ������׽��Ϊ-����������ν���
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int profit = 0, temp_profit = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			temp_profit = prices[i] - prices[i - 1];
			if (temp_profit > 0)
			{
				profit += temp_profit;
			}
		}
		return profit;
    }
};