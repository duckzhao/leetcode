#include<vector>
using namespace std;


// ����������̳���飬ֻҪ�������ֻ���λ��(ǰ�Һ�Ϊ0)��n--��
// ֱ����̳��������������n==0
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		bool flag = false;
		if (!n)
		{
			return true;
		}

		// ���Ǳ߽�ͽ�β����������������Ǹ�ͷβ����һ��0
		flowerbed.insert(flowerbed.begin(), 0);
		flowerbed.push_back(0);

		for (int i = 1; i < flowerbed.size() - 1; i++)
		{
			// ֻ������3��0������
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