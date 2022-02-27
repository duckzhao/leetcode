#include<vector>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // 定义 四个节点的操作路径
        vector<vector<int>> ops = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
        
        // 定义最大路径
        int max_area = 0;

        // 开始遍历每个节点
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                vector<int> next = { i, j };

                // 如果这个节点是1就放进去判断
                if (grid[next[0]][next[1]] == 1)
                {
                    grid[next[0]][next[1]] = 0; // 已经算过的岛屿标记为0，防止二次遍历
                    int temp = getArea(next, grid, ops);
                    max_area = temp > max_area ? temp : max_area;
                }
            }
        }
        return max_area;
    }

    // 定义子函数，用于从某个节点出发寻找身边四个节点是否满足陆地
    int getArea(vector<int> middle, vector<vector<int>>& grid, vector<vector<int>>& ops) {
        // 定义这个节点所在的岛屿大小
        int area = 1;
        grid[middle[0]][middle[1]] = 0; // 已经算过的岛屿标记为0，防止二次遍历

        // 寻找四个节点是否为岛屿
        for (auto op : ops )
        {
            // 拿到下一个岛屿的坐标
            vector<int> next = { middle[0] + op[0], middle[1] + op[1] };
            // 如果next不超出边界且为1才遍历
            if (next[0] >= 0 && next[1] >= 0 && next[0] < grid.size() && next[1] < grid[0].size() && grid[next[0]][next[1]] == 1)
            {
                area += getArea(next, grid, ops);   // 求的下一个岛屿的连接面积
            }
            else
            {
                continue;
            }
            
        }
        // 当没得递归了，说明这个岛屿走到头了，返回当前的面积
        return area;
    }
};

int main695() {
    Solution s;
    vector<vector<int>> v = { {0, 0, 0, 0, 0, 0} };
    s.maxAreaOfIsland(v);
    return 0;
}