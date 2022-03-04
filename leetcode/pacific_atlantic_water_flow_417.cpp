#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // 从po和ao分别 逆流而上进行流动，将能流到的点标记为1
        // 如果最后两个矩阵相加，点数和为2，则说明该点能够两边都流到
        int m = heights.size(), n = heights[0].size();
        // 定义返回值
        vector<vector<int>> retval;
        // 标记是否po和ao边界能到达该点
        vector<vector<int>> po_arrive(m, vector<int>(n, 0));
        vector<vector<int>> ao_arrive(m, vector<int>(n, 0));
        // 遍历上下两个边界，i表示列数
        for (int i = 0; i < n; i++)
        {
            dfs(0, i, m, n, po_arrive, heights);
            dfs(m - 1, i, m, n, ao_arrive, heights);
        }
        // 遍历左右两个边界，i表示列数
        for (int i = 0; i < m; i++)
        {
            dfs(i, 0, m, n, po_arrive, heights);
            dfs(i, n - 1, m, n, ao_arrive, heights);
        }
        // 当对两个海洋都给中间流了以后，相当于把所有两个海洋口能够遍历到的cell
        // 都进行了标记，相加这些标记，如果和为2，则说明是答案
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (po_arrive[i][j] + ao_arrive[i][j] == 2)
                {
                    retval.push_back({ i, j });
                }
            }
        }
        return retval;
    }

    // 从po边界开始给中间进行遍历
    void dfs(int i, int j, int m, int n, vector<vector<int>>& arrived, vector<vector<int>>& heights) {
        // 先对送进来的点进行标记
        arrived[i][j] = 1;

        vector<vector<int>> ops = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        for (auto op : ops)
        {
            int newx = op[0] + i;
            int newy = op[1] + j;
            // 判断下一个点是否越界
            if (newx < 0 || newy < 0 || newx >= m || newy >= n)
            {
                continue;
            }
            // 不越界的话判断新点的height是否高于ij点
            if (heights[i][j] > heights[newx][newy])
            {
                continue;
            }
            // 新点高度也满足的话判断该点是否已经被标记
            if (arrived[newx][newy] != 0)
            {
                continue;
            }
            // 满足条件且没被标记，则标记该点并对该点进行dfs
            dfs(newx, newy, m, n, arrived, heights);
        }
    }
};

int main417() {

    Solution s;
    vector<vector<int>> heights = { {1,1},{1,1},{1,1} };
    s.pacificAtlantic(heights);
    return 0;
}