#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;


// ǰk����Ƶ�����ֵĽ��������
// 1. ����mapͳ��ÿ�����ֳ��ֵ�Ƶ�ʣ�
// 2. ��������ΪK�����ȼ�����Ԫ��Ϊpair<int, int>��С���ѣ����Ƚ��ȳ���--->��ν���ȼ����о��� ���Զ���һ���º����������ڲ��ᰴ�ո÷º����Ĺ���Բ������ݽ����Զ�����
// �������е�ÿ��Ԫ��Ҫ�� key �� value��key�Ǹ����֣�����return����value�Ǹ����ֳ��ֵ�Ƶ�ʣ�����queue�ο��º����ڲ�����
// 3. ����map��map�е�Ԫ�ش�ֵ����q�У���ά�ֶ���sizeΪK
// 4. �������ΪK�Ķ����е����ݾ�������Ҫ��K����Ƶ���֣�


// ���ȼ����и��https://blog.csdn.net/weixin_36888577/article/details/79937886


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // ���ȶ�nums����Ƶ��ͳ�ƣ�ʹ�� unordered_map(dict) ���
        // map �е� elementʵ���Ͼ���һ��һ����pair�ԣ����Ϳ��Կ���Ϊpair<int, int>
        unordered_map<int, int> nums_frequent;
        for (int i = 0; i < nums.size(); i++)
        {
            nums_frequent[nums[i]]++;   // �����ʵ�key������ʱ��c++����ø�value���Ĭ�Ϲ����ʼ��һ����
                                        // eg string���;��ǿ��ַ�����int�����0��������ͳ��Ƶ��map[key]++;
        }


        // ���� ����ΪK�� ���ȼ�����priority_queue�������Ԫ��
        // 1. ��������priority_queue�Զ�����ķº���
		class MyCompare
		{
		public:
            // �º����Ĳ��������� ������е�Ԫ�����ͱ���һ�£�const���α�ʾ ���ɸ��ĸ�Ԫ�ص�ֵ���̶�д����Ҳ����ֱ�������ڲ���ǰ
            bool operator() (pair<int, int> p1, pair<int, int>p2) const {
                // > ��ʾС�ĸ�ͷ���ߣ�С���ѣ���< ��ʾ��ĸ�ͷ���ߣ��󶥶ѣ�
                return p1.second > p2.second;
            }

		};
        // 2. �������ȼ����� q
        // ��һ�������� ������е�Ԫ�أ��ڶ����� �����ڴ�Ÿ�Ԫ�ص��������ͣ� �������� �������ȼ�����ķº���class
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompare> q;

        // 3. ������q�д�element����ʵ���ǰ�map��nums_frequent����Ԫ��һ��һ�����������nums_frequent�������Ƕ�������ȼ�˳���Ϊ�������
        // ���� nums_frequent
        for (unordered_map<int, int>::iterator it = nums_frequent.begin(); it != nums_frequent.end(); it++)
        {
            q.push(*it);
            if (q.size() > k)
            {
                q.pop();    // һ����ǰ����Ԫ�س���k������ǰ��k+1��Ԫ�أ�����˵�topԪ��second����һ������С�ģ���Ƶ����С������pop��
            }
        }

        // 4. ������ȡ����sizeΪK�Ķ�����ÿ��Ԫ�ص�first������ӦƵ�ʵ����֣�������vector�з���
        // �������vector�У���Ϊ��pop������Ƶ��С
        vector<int> retval(k);
        for (int i = k-1; i >= 0; i--)
        {
            retval[i] = q.top().first;
            q.pop();
        }
        return retval;
    }
};