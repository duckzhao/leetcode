#include<vector>
#include<algorithm>
using namespace std;

// 解决方案：移除最小的元素使得剩下的区间不重叠，显然能够想到这与每个元素的begin和end值
// 大小有关，因此首先想到排序操作，vector中存放的是长度为2的vector，想要对它排序就要先
// 想好排序规则，并自己写仿函数实现。我们按照begin的大小进行元素排序。
// 算法核心：假设迭代到第i的位置，比较i.second和i+1.first的大小，如果i.second<=1.first，
// 则这两个区间不重叠，继续向下迭代，i++；如果i.second>1.first，说明这两个区间有重叠，
// 那么这两个区间一定要去掉一个，所以我们立即执行去掉操作，去掉其中second更大的元素，
// 这样就可以给后面的元素留下更大的空间,后面元素的first更大概率满足大于前面元素second的条件

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		
		class MyCompare
		{
		public:
			bool operator() (vector<int>& v1, vector<int>& v2) const {
				return v1[0] < v2[0];
			}
		};

		sort(intervals.begin(), intervals.end(), MyCompare());

		vector<int> v = intervals[0];
		int count = 0;

		for (int i = 1; i < intervals.size(); i++)
		{
			if (v[1] <= intervals[i][0])
			{
				v = intervals[i];
				continue;
			}
			else
			{
				count++;
				if (v[1] >= intervals[i][1])
				{
					v = intervals[i];
				}
			}
		}
		return count;

    }
};