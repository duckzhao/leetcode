#include<vector>
#include<algorithm>
using namespace std;


// 要进行身高排序的同时考虑到前面有几个比他高，该问题大概率要先排序一次
// 先排序可以达到整体有序，再根据second的值进行微调即可
// 经过思考，我们采用降序排列的方式，先满足大数字，再满足小数字，
// 因为排好大数字后再排小数字，小数字变化不会对大数字产生影响

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		// 定义降序排列规则，优先按照身高排序，身高一致时按照second排序
		// 对第二个元素也进行排序很重要！！！第二个元素升序，第一个元素降序
		class MyCompare
		{
		public:
			bool operator() (vector<int>& v1, vector<int>& v2)const {
				if (v1[0] > v2[0])
				{
					return true;
				}
				else if (v1[0] < v2[0])
				{
					return false;
				}
				else
				{
					return v1[1] > v2[1] ? false : true;
				}
			}
		};

		sort(people.begin(), people.end(), MyCompare());

		// 开始写算法
		vector<vector<int>> v;
		auto p = v.begin();
		for (int i = 0; i < people.size(); i++)
		{
			// 要插入，不能赋值
			v.insert((p + people[i][1]), people[i]);
			p = v.begin();
		}
		return v;
    }
};