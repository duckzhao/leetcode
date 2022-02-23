#include<queue>
#include<math.h>
#include<set>
using namespace std;


// 可以将每个整数看成图中的一个节点，如果两个整数之差为一个平方数，那么这两个整数所在的节点就有一条边。
// 要求解最小的平方数数量，就是求解从节点 n 到节点 0 的最短路径。
class Solution {
public:
    int numSquares(int n) {
        queue<int> q;   // 1.队列，存放待分解为完全平方数的数字
        set<int> s;     // 2.标记遍历过的节点，即下一个待分解的数
        q.push(n);
        s.insert(n);

        int count = 0;  // 定义最短路径计数器
        int size = 0;   // 存放每轮队列要遍历的次数

        while (!q.empty())
        {
            count++;
            size = q.size();
            while (size--)
            {
                int num = q.front();
                q.pop();
                // 开始遍历小于num的所有完全平方数，找到下一个节点，该节点 = num-完全平方数
                int i = 0;
                while (++i)
                {
                    // next是下一个节点，直接用i^2去遍历，降低时间复杂度
                    int next = num - i * i;
                    if (next < 0)
                    {
                        break;
                    }

                    // next 要 没被遍历过，如果已经被标记了，则此时遍历就不是最短路径了，直接跳过即可
                    if (s.find(next) != s.end())
                    {
                        continue;
                    }

                    if (next == 0)
                    {
                        return count;
                    }
                    q.push(next);
                    s.insert(next);
                }
            }
        }
        return -1;
    }
};

int main279() {
    Solution s;
    s.numSquares(12);
    return 0;
}