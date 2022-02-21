#include<vector>
#include<iostream>
using namespace std;


// 由于该问题和日期有关，所以数组的顺序不能改变，因此不能排序
// 每天都进行一次股票买卖，如果当此交易的利润>0，就保留这次利润，继续买卖
// 小于0就重置利润，开始下次买卖，记录买卖过程的最大利润，当遍历完vector后得到的最大利润就是结果
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, temp_profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            // 得到截至本次交易的最大利润
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

// 另一个思路是找截至到i区间为止的，最小点和最大利润即可，用最小点和i点一直比较，
// 如果新的点更小，则之前就产生了最大点，否则赔了，如果新的点更大，则该点就是最大利润点
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