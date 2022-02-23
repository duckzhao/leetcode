#include<vector>
#include<set>
#include<queue>
using namespace std;

// 记录遍历的点到set中，每次判断新的点在不在set中，防止走重复，时间复杂度高，多了好多循环查找重复元素
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() - 1;
        // 排除[0][0]和[n-1][n-1]为1的特殊情况
        if (grid[0][0] or grid[n][n])
        {
            return -1;
        }

        // 排除仅[0][0] = 0的特殊情况
        if (n == 0)
        {
            return 1;
        }

        // 否则，使用BFS进行无权最短路径搜索
        set<vector<int>> olds;    // 存储已经遍历过的节点，用vector在查找出先过的元素时会超时，所以改用map
        vector<vector<int>> nows;    // 存储正在遍历的节点
        vector<vector<int>> nexts;   // 存储下一轮需要遍历的节点
        // 更新可遍历节点的状态
        nows.push_back({ 0, 0 });
        olds.insert({ 0, 0 });
        // 一共需要走几步
        int nums = 1;
        // 定义8中临近单元格的移动方式
        vector<vector<int>> moves = { {-1, -1}, {0, -1}, {1, -1}, {-1, 1}, {1, 0}, {1, 1}, {0, 1}, {-1, 0} };
        // 当前遍历节点为空，说明到不了终点了
        while (!nows.empty())
        {
            nums++;
            for (auto now : nows)
            {
                // 验证8个临近单元哪种可以成为下一步的点
                for (auto move : moves)
                {
                    vector<int> next = { now[0] + move[0], now[1] + move[1] };
                    // 判断下一个点是否合格
                    // 首先判断没有越界
                    if (next[0] >= 0 && next[0] <= n && next[1] >= 0 && next[1] <= n)
                    {
                        // 其次判断值为0 且 以前没有遍历过
                        if (!grid[next[0]][next[1]] && olds.find(next) == olds.end())
                        {
                            // 如果是终点直接返回即可
                            if (next[0] == n && next[1] == n)
                            {
                                return nums;
                            }
                            // 否则将该节点追加进nexts中
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

// 在原始数据上标记重复的点（直接修改原始数据），每次判断该点数值的时候顺便就判断是否走过了，时间复杂度低
class Solution1 {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() - 1;
        // 排除[0][0]和[n-1][n-1]为1的特殊情况
        if (grid[0][0] or grid[n][n])
        {
            return -1;
        }

        // 排除仅[0][0] = 0的特殊情况
        if (n == 0)
        {
            return 1;
        }

        // 否则，使用BFS进行无权最短路径搜索
        vector<vector<int>> nows;    // 存储正在遍历的节点
        vector<vector<int>> nexts;   // 存储下一轮需要遍历的节点
        // 更新可遍历节点的状态
        nows.push_back({ 0, 0 });
        grid[0][0] = 1;     // 将起点标记为阻塞，即已经遍历过的状态
        // 一共需要走几步
        int nums = 1;
        // 定义8中临近单元格的移动方式
        vector<vector<int>> moves = { {-1, -1}, {0, -1}, {1, -1}, {-1, 1}, {1, 0}, {1, 1}, {0, 1}, {-1, 0} };
        // 当前遍历节点为空，说明到不了终点了
        while (!nows.empty())
        {
            nums++;
            for (auto now : nows)
            {
                // 验证8个临近单元哪种可以成为下一步的点
                for (auto move : moves)
                {
                    vector<int> next = { now[0] + move[0], now[1] + move[1] };
                    // 判断下一个点是否合格
                    // 首先判断没有越界
                    if (next[0] >= 0 && next[0] <= n && next[1] >= 0 && next[1] <= n)
                    {
                        // 其次判断值为0
                        if (!grid[next[0]][next[1]])
                        {
                            // 如果是终点直接返回即可
                            if (next[0] == n && next[1] == n)
                            {
                                return nums;
                            }
                            // 否则将该节点追加进nexts中
                            else
                            {
                                grid[next[0]][next[1]] = 1;     // 标记：将遍历过的元素标记为1，以后就不会再遍历它了
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

// 为了加快速度，改用queue队列来记录 需要遍历的节点，而不是使用两个vector来做
class Solution2 {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() - 1;
        // 排除[0][0]和[n-1][n-1]为1的特殊情况
        if (grid[0][0] or grid[n][n])
        {
            return -1;
        }

        // 排除仅[0][0] = 0的特殊情况
        if (n == 0)
        {
            return 1;
        }

        // 否则，使用BFS进行无权最短路径搜索
        queue<vector<int>> nows;    // 存储正在遍历的节点

        // 更新可遍历节点的状态
        nows.push({ 0, 0 });
        grid[0][0] = 1;
        // 一共需要走几步
        int nums = 1;
        // 定义8中临近单元格的移动方式
        vector<vector<int>> moves = { {-1, -1}, {0, -1}, {1, -1}, {-1, 1}, {1, 0}, {1, 1}, {0, 1}, {-1, 0} };
        // 当前遍历节点为空，说明到不了终点了
        while (!nows.empty())
        {
            nums++;
            int size = nows.size();
            while (size--)
            {
                vector<int> now = nows.front();     // front配合pop遍历queue，队列，先进先出，先进的在front，索引小
                nows.pop();
                // 验证8个临近单元哪种可以成为下一步的点
                for (auto move : moves)
                {
                    vector<int> next = { now[0] + move[0], now[1] + move[1] };
                    // 判断下一个点是否合格
                    // 首先判断没有越界
                    if (next[0] >= 0 && next[0] <= n && next[1] >= 0 && next[1] <= n)
                    {
                        // 其次判断值为0
                        if (!grid[next[0]][next[1]])
                        {
                            // 如果是终点直接返回即可
                            if (next[0] == n && next[1] == n)
                            {
                                return nums;
                            }
                            // 否则将该节点追加进nexts中
                            else
                            {
                                grid[next[0]][next[1]] = 1;     // 标记：将遍历过的元素标记为1，以后就不会再遍历它了
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