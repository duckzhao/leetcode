#include<vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> ops = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        int count = 0;

        // ����������ά���񣬲鿴���Ƿ��ǵ���
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    grid[i][j] = '0';    // ���
                    vector<int> point = { i, j };
                    dfs(point, grid, ops);
                }
            }
        }
        return count;
    }

    // ����ڽڵ㣬��ʼdfs��������ߵ��ĸ��ڵ㣨������½�أ����Լ����ĸ��ܵ��������½��
    // ��������½�ض���Ϊ0����ֹ���α���
    void dfs(vector<int>& point, vector<vector<char>>& grid, vector<vector<int>>& ops) {
        // ��ʼ�����ĸ��ڵ�
        for (auto op : ops)
        {
            vector<int> next = { point[0] + op[0], point[1] + op[1] };
            // �ж�next�Ƿ�Խ��
            if (next[0] < 0 || next[1] < 0 || next[0] >= grid.size() || next[1] >= grid[0].size())
            {
                continue;
            }

            // ���next�ǵ���
            if (grid[next[0]][next[1]] == '1')
            {
                grid[next[0]][next[1]] = '0';   // ���
                dfs(next, grid, ops);
            }
        }
    }

};