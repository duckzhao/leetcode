#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;


// 前k个高频率数字的解决方案：
// 1. 创建map统计每个数字出现的频率；
// 2. 构建容量为K的优先级队列元素为pair<int, int>（小顶堆），先进先出；--->所谓优先级队列就是 可以定义一个仿函数，队列内部会按照该仿函数的规则对插入数据进行自动排序
// （队列中的每个元素要有 key 和 value，key是该数字（用于return），value是该数字出现的频率，用于queue参考仿函数内部排序）
// 3. 遍历map将map中的元素存值队列q中，并维持队列size为K
// 4. 最后容量为K的队列中的数据就是我们要的K个高频数字；


// 优先级队列概念：https://blog.csdn.net/weixin_36888577/article/details/79937886


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 首先对nums进行频率统计，使用 unordered_map(dict) 完成
        // map 中的 element实际上就是一个一个的pair对，类型可以看作为pair<int, int>
        unordered_map<int, int> nums_frequent;
        for (int i = 0; i < nums.size(); i++)
        {
            nums_frequent[nums[i]]++;   // 当访问的key不存在时，c++会调用该value类的默认构造初始化一个数
                                        // eg string类型就是空字符串，int类就是0，常用来统计频率map[key]++;
        }


        // 创建 容量为K的 优先级队列priority_queue，并填充元素
        // 1. 创建用于priority_queue自动排序的仿函数
		class MyCompare
		{
		public:
            // 仿函数的参数类型与 进入队列的元素类型保持一致，const修饰表示 不可更改该元素的值，固定写法，也可以直接修饰在参数前
            bool operator() (pair<int, int> p1, pair<int, int>p2) const {
                // > 表示小的给头部走（小顶堆），< 表示大的给头部走（大顶堆）
                return p1.second > p2.second;
            }

		};
        // 2. 创建优先级队列 q
        // 第一个参数是 进入队列的元素；第二个是 队列内存放该元素的容器类型； 第三个是 控制优先级排序的仿函数class
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompare> q;

        // 3. 给队列q中存element，其实就是把map（nums_frequent）的元素一个一个存进来，让nums_frequent按照我们定义的优先级顺序变为有序队列
        // 遍历 nums_frequent
        for (unordered_map<int, int>::iterator it = nums_frequent.begin(); it != nums_frequent.end(); it++)
        {
            q.push(*it);
            if (q.size() > k)
            {
                q.pop();    // 一旦当前队列元素超过k，即当前有k+1个元素，则最顶端的top元素second属性一定是最小的，即频率最小，所以pop它
            }
        }

        // 4. 遍历（取出）size为K的队列中每个元素的first（即对应频率的数字），存入vector中返回
        // 逆序存入vector中，因为先pop出来的频率小
        vector<int> retval(k);
        for (int i = k-1; i >= 0; i--)
        {
            retval[i] = q.top().first;
            q.pop();
        }
        return retval;
    }
};