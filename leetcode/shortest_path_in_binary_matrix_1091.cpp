#include<vector>
#include<set>
#include<queue>
using namespace std;

// ��¼�����ĵ㵽set�У�ÿ���ж��µĵ��ڲ���set�У���ֹ���ظ���ʱ�临�Ӷȸߣ����˺ö�ѭ�������ظ�Ԫ��
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() - 1;
        // �ų�[0][0]��[n-1][n-1]Ϊ1���������
        if (grid[0][0] or grid[n][n])
        {
            return -1;
        }

        // �ų���[0][0] = 0���������
        if (n == 0)
        {
            return 1;
        }

        // ����ʹ��BFS������Ȩ���·������
        set<vector<int>> olds;    // �洢�Ѿ��������Ľڵ㣬��vector�ڲ��ҳ��ȹ���Ԫ��ʱ�ᳬʱ�����Ը���map
        vector<vector<int>> nows;    // �洢���ڱ����Ľڵ�
        vector<vector<int>> nexts;   // �洢��һ����Ҫ�����Ľڵ�
        // ���¿ɱ����ڵ��״̬
        nows.push_back({ 0, 0 });
        olds.insert({ 0, 0 });
        // һ����Ҫ�߼���
        int nums = 1;
        // ����8���ٽ���Ԫ����ƶ���ʽ
        vector<vector<int>> moves = { {-1, -1}, {0, -1}, {1, -1}, {-1, 1}, {1, 0}, {1, 1}, {0, 1}, {-1, 0} };
        // ��ǰ�����ڵ�Ϊ�գ�˵���������յ���
        while (!nows.empty())
        {
            nums++;
            for (auto now : nows)
            {
                // ��֤8���ٽ���Ԫ���ֿ��Գ�Ϊ��һ���ĵ�
                for (auto move : moves)
                {
                    vector<int> next = { now[0] + move[0], now[1] + move[1] };
                    // �ж���һ�����Ƿ�ϸ�
                    // �����ж�û��Խ��
                    if (next[0] >= 0 && next[0] <= n && next[1] >= 0 && next[1] <= n)
                    {
                        // ����ж�ֵΪ0 �� ��ǰû�б�����
                        if (!grid[next[0]][next[1]] && olds.find(next) == olds.end())
                        {
                            // ������յ�ֱ�ӷ��ؼ���
                            if (next[0] == n && next[1] == n)
                            {
                                return nums;
                            }
                            // ���򽫸ýڵ�׷�ӽ�nexts��
                            else
                            {
                                olds.insert(next);
                                nexts.push_back(next);
                            }
                        }
                    }
                }
            }
            nows = nexts;
            nexts.clear();
        }
        return -1;
    }
};

// ��ԭʼ�����ϱ���ظ��ĵ㣨ֱ���޸�ԭʼ���ݣ���ÿ���жϸõ���ֵ��ʱ��˳����ж��Ƿ��߹��ˣ�ʱ�临�Ӷȵ�
class Solution1 {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() - 1;
        // �ų�[0][0]��[n-1][n-1]Ϊ1���������
        if (grid[0][0] or grid[n][n])
        {
            return -1;
        }

        // �ų���[0][0] = 0���������
        if (n == 0)
        {
            return 1;
        }

        // ����ʹ��BFS������Ȩ���·������
        vector<vector<int>> nows;    // �洢���ڱ����Ľڵ�
        vector<vector<int>> nexts;   // �洢��һ����Ҫ�����Ľڵ�
        // ���¿ɱ����ڵ��״̬
        nows.push_back({ 0, 0 });
        grid[0][0] = 1;     // �������Ϊ���������Ѿ���������״̬
        // һ����Ҫ�߼���
        int nums = 1;
        // ����8���ٽ���Ԫ����ƶ���ʽ
        vector<vector<int>> moves = { {-1, -1}, {0, -1}, {1, -1}, {-1, 1}, {1, 0}, {1, 1}, {0, 1}, {-1, 0} };
        // ��ǰ�����ڵ�Ϊ�գ�˵���������յ���
        while (!nows.empty())
        {
            nums++;
            for (auto now : nows)
            {
                // ��֤8���ٽ���Ԫ���ֿ��Գ�Ϊ��һ���ĵ�
                for (auto move : moves)
                {
                    vector<int> next = { now[0] + move[0], now[1] + move[1] };
                    // �ж���һ�����Ƿ�ϸ�
                    // �����ж�û��Խ��
                    if (next[0] >= 0 && next[0] <= n && next[1] >= 0 && next[1] <= n)
                    {
                        // ����ж�ֵΪ0
                        if (!grid[next[0]][next[1]])
                        {
                            // ������յ�ֱ�ӷ��ؼ���
                            if (next[0] == n && next[1] == n)
                            {
                                return nums;
                            }
                            // ���򽫸ýڵ�׷�ӽ�nexts��
                            else
                            {
                                grid[next[0]][next[1]] = 1;     // ��ǣ�����������Ԫ�ر��Ϊ1���Ժ�Ͳ����ٱ�������
                                nexts.push_back(next);
                            }
                        }
                    }
                }
            }
            nows = nexts;
            nexts.clear();
        }
        return -1;
    }
};

// Ϊ�˼ӿ��ٶȣ�����queue��������¼ ��Ҫ�����Ľڵ㣬������ʹ������vector����
class Solution2 {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() - 1;
        // �ų�[0][0]��[n-1][n-1]Ϊ1���������
        if (grid[0][0] or grid[n][n])
        {
            return -1;
        }

        // �ų���[0][0] = 0���������
        if (n == 0)
        {
            return 1;
        }

        // ����ʹ��BFS������Ȩ���·������
        queue<vector<int>> nows;    // �洢���ڱ����Ľڵ�

        // ���¿ɱ����ڵ��״̬
        nows.push({ 0, 0 });
        grid[0][0] = 1;
        // һ����Ҫ�߼���
        int nums = 1;
        // ����8���ٽ���Ԫ����ƶ���ʽ
        vector<vector<int>> moves = { {-1, -1}, {0, -1}, {1, -1}, {-1, 1}, {1, 0}, {1, 1}, {0, 1}, {-1, 0} };
        // ��ǰ�����ڵ�Ϊ�գ�˵���������յ���
        while (!nows.empty())
        {
            nums++;
            int size = nows.size();
            while (size--)
            {
                vector<int> now = nows.front();     // front���pop����queue�����У��Ƚ��ȳ����Ƚ�����front������С
                nows.pop();
                // ��֤8���ٽ���Ԫ���ֿ��Գ�Ϊ��һ���ĵ�
                for (auto move : moves)
                {
                    vector<int> next = { now[0] + move[0], now[1] + move[1] };
                    // �ж���һ�����Ƿ�ϸ�
                    // �����ж�û��Խ��
                    if (next[0] >= 0 && next[0] <= n && next[1] >= 0 && next[1] <= n)
                    {
                        // ����ж�ֵΪ0
                        if (!grid[next[0]][next[1]])
                        {
                            // ������յ�ֱ�ӷ��ؼ���
                            if (next[0] == n && next[1] == n)
                            {
                                return nums;
                            }
                            // ���򽫸ýڵ�׷�ӽ�nexts��
                            else
                            {
                                grid[next[0]][next[1]] = 1;     // ��ǣ�����������Ԫ�ر��Ϊ1���Ժ�Ͳ����ٱ�������
                                nows.push(next);
                            }
                        }
                    }
                }
            }
            
        }
        return -1;
    }
};

int main1091() {
    Solution2 s;
    vector<vector<int>> grid = { {0, 0, 0},{1, 1, 0},{1, 1, 0} };

    s.shortestPathBinaryMatrix(grid);
    return 0;
}