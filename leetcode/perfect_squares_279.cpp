#include<queue>
#include<math.h>
#include<set>
using namespace std;


// ���Խ�ÿ����������ͼ�е�һ���ڵ㣬�����������֮��Ϊһ��ƽ��������ô�������������ڵĽڵ����һ���ߡ�
// Ҫ�����С��ƽ�����������������ӽڵ� n ���ڵ� 0 �����·����
class Solution {
public:
    int numSquares(int n) {
        queue<int> q;   // 1.���У���Ŵ��ֽ�Ϊ��ȫƽ����������
        set<int> s;     // 2.��Ǳ������Ľڵ㣬����һ�����ֽ����
        q.push(n);
        s.insert(n);

        int count = 0;  // �������·��������
        int size = 0;   // ���ÿ�ֶ���Ҫ�����Ĵ���

        while (!q.empty())
        {
            count++;
            size = q.size();
            while (size--)
            {
                int num = q.front();
                q.pop();
                // ��ʼ����С��num��������ȫƽ�������ҵ���һ���ڵ㣬�ýڵ� = num-��ȫƽ����
                int i = 0;
                while (++i)
                {
                    // next����һ���ڵ㣬ֱ����i^2ȥ����������ʱ�临�Ӷ�
                    int next = num - i * i;
                    if (next < 0)
                    {
                        break;
                    }

                    // next Ҫ û��������������Ѿ�������ˣ����ʱ�����Ͳ������·���ˣ�ֱ����������
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