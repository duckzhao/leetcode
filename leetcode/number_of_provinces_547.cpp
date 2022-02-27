#include<vector>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // 处理特殊情况
        if (isConnected.size() == 1)
        {
            return 1;
        }

        // 返回值
        int count = 0;

        int n = isConnected.size();
        // 调用dfs遍历每个城市
        for (int i = 0; i < n; i++)
        {
            if (isConnected[i][i] == 1)
            {
                count++;
                // 将对角线元素置0
                isConnected[i][i] = 0;
                dfs(i, n, isConnected);
            }
        }
        return count;
    }

    // 使用dfs遍历 loc 的这一行（loc+1，n-1] 和这一列 [0, loc-1]
    void dfs(int loc, int n, vector<vector<int>>& isConnected) {
        // 遍历loc这一行,i控制列位置
        for (int i = loc + 1; i < n; i++)
        {
            // 如果有 城市和 这列城市连接，把这个城市的对角线设为0
            if (isConnected[loc][i] == 1)
            {
                isConnected[loc][i] = 0;
                isConnected[i][i] = 0;
                // 深度遍历
                dfs(i, n, isConnected);
            }
        }

        // 遍历loc这一列
        for (int j = 0; j < loc; j++)
        {
            // 如果有 城市和 这列城市连接，把这个城市的对角线设为0
            if (isConnected[j][loc] == 1)
            {
                isConnected[j][loc] = 0;
                isConnected[j][j] = 0;
                // 深度遍历
                dfs(j, n, isConnected);
            }
        }
    }
};