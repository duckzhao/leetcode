#include<vector>
using namespace std;

// 有天数次序限制，还是不能排序
// 每相邻两天都进行一次操作，如果交易结果为+，就计入profit中，
// 如果交易结果为-，就舍弃这次交易
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