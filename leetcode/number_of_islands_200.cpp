#include<vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> ops = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        int count = 0;

        // 遍历整个二维网格，查看他是否是岛屿
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    grid[i][j] = '0';    // 标记
                    vector<int> point = { i, j };
                    dfs(point, grid, ops);
                }
            }
        }
        return count;
    }

    // 从入口节点，开始dfs遍历它身边的四个节点（必须是陆地），以及这四个能到达的所有陆地
    // 遍历过的陆地都置为0，防止二次遍历
    void dfs(vector<int>& point, vector<vector<char>>& grid, vector<vector<int>>& ops) {
        // 开始遍历四个节点
        for (auto op : ops)
        {
            vector<int> next = { point[0] + op[0], point[1] + op[1] };
            // 判断next是否越界
            if (next[0] < 0 || next[1] < 0 || next[0] >= grid.size() || next[1] >= grid[0].size())
            {
                continue;
            }

            // 如果next是岛屿
            if (grid[next[0]][next[1]] == '1')
            {
                grid[next[0]][next[1]] = '0';   // 标记
                dfs(next, grid, ops);
            }
        }
    }

};