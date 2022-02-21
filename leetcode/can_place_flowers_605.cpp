#include<vector>
using namespace std;


// 遍历整个花坛数组，只要发现能种花的位置(前我后都为0)，n--，
// 直到花坛遍历结束，或者n==0
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		bool flag = false;
		if (!n)
		{
			return true;
		}

		// 考虑边界和结尾两种特殊情况，我们给头尾各增一个0
		flowerbed.insert(flowerbed.begin(), 0);
		flowerbed.push_back(0);

		for (int i = 1; i < flowerbed.size() - 1; i++)
		{
			// 只有连续3个0可以种
			if (flowerbed[i - 1] + flowerbed[i] + flowerbed[i + 1] == 0)
			{
				flowerbed[i] = 1;
				n--;
				if (n <= 0)
				{
					flag = true;
					break;
				}
			}
		}
		return flag;
    }
};