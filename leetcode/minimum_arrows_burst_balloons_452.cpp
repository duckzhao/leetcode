#include<vector>
#include<algorithm>
using namespace std;

// 想要找到最少的射箭次数，就需要找到每一组能够使用重叠方式，一次射穿的气球最多。
// 因此肯定需要对原始的vector进行排序，只有在有序的状态下才能仅遍历一次就知道一个气球
// 有没有和其他气球重叠。我们使用每个气球的begin点坐标进行排序。

// 排好序后，执行核心算法：从最小的x开始，找到一次能最多射穿的气球(下一个气球应该和前面气球的交集有交集)，
// 然后射穿，再给后找。不需要执着于非要一次射穿很多重叠的气球，因为剩下的气球还是要费
// 很多针去射，因此保证每次都射穿最多的气球即可。

class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {
		// 1. 排序
		class MyCompare
		{
		public:
			bool operator() (vector<int>& v1, vector<int>& v2)const {
				return v1[0] < v2[0];
			}
		};
		sort(points.begin(), points.end(), MyCompare());

		// 2. 开始迭代，将可射重叠区域定义为容器v，如果index点 的起始坐标小于等于容器v的结束坐标，
		// 则说明这两个区气球有重叠，缩小重叠区间，继续判断i+2气球是否和新的可射重叠区域有重叠，
		// 当判断到j无重叠后，射爆重叠区域，count++。v=index指向的新气球的区间，作为新的重叠区域

		vector<int> v = points[0];
		int count = 0, index = 1;
		int size = points.size();
		while (index < size)
		{
			while (index < size)
			{
				// 若index的头小于当前气球的尾，说明两个气球相交
				if (v[1] >= points[index][0])
				{
					// 满足的话需要修改交集范围
					v[0] = points[index][0];
					v[1] = v[1] > points[index][1] ? points[index][1] : v[1];
					index++;
				}
				// 不满足，射爆之前的所有气球，让起始气球变为index指向的气球，开始下一轮循环
				else
				{
					v = points[index];
					index++;
					count++;
					break;
				}
			}
		}
		// 说明是遍历到末尾退出的，有一批气球没爆，射爆它
		count++;
		return count;
	}
};