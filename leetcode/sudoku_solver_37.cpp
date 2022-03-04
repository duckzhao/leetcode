#include<vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // 每一行还缺什么，每一列还缺什么数，每一个cell还缺什么数
        vector<vector<int>> rows(9, vector<int>(9, 0)), cols, cells;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                rows[i][j] = j + 1;
            }
        }
        cols = rows;
        cells = rows;

        // 遍历board，将每一行有的数，设为0，剩下的非0就是缺的数
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char c = board[i][j];
                if (c != '.')
                {
                    int temp = c - '0'; // 拿到c表示的数字
                    rows[i][temp - 1] = 0;
                    cols[j][temp - 1] = 0;
                    cells[(i / 3) * 3 + j / 3][temp - 1] = 0;
                }
            }
        }
        int x = 0, y = 0;
        while (true)
        {
            if (board[x][y] == '.')
            {
                break;
            }
            y++;
            if (y == 9)
            {
                y = 0;
                x++;
            }
            // 如果找到最后一个位置，都没有.的话，说明任务完成了，直接return t
            if (x == 9)
            {
                return;
            }
        }
        dfs(board, rows, cols, cells, x, y);
    }

    bool dfs(vector<vector<char>>& board, vector<vector<int>>& rows, vector<vector<int>>& cols, vector<vector<int>>& cells, int x, int y) {
        // 判断
        vector<int> inter = getInter(rows, cols, cells, x, y);
        if (inter.empty())
        {
            return false;
        }
        // 补充一个return t的条件 x y到了最后一个，且inter不为空
        if (x == 8 && y == 8)
        {
            board[8][8] = inter[0] + '0';
            return true;
        }

        // 否则继续选择数
        for (int i = 0; i < inter.size(); i++)
        {
            // 数字转为char
            int temp = inter[i];    // 保存这个数字
            char c = inter[i] + '0';
            board[x][y] = c;
            // 在rows等中 标记当前被用的这个数
            rows[x][temp - 1] = 0;
            cols[y][temp - 1] = 0;
            cells[(x / 3) * 3 + y / 3][temp - 1] = 0;
            // 进行下一轮dfs时，只有是 . 的格子才能进去
            int next_y = y + 1;
            int next_x = x;
            while (true)
            {
                if (next_y == 9)
                {
                    next_y = 0;
                    next_x++;
                }
                // 如果找到最后一个位置，都没有.的话，说明任务完成了，直接return t
                if (next_x == 9)
                {
                    return true;
                }
                if (board[next_x][next_y] == '.')
                {
                    break;
                }
                next_y++;
            }
            // 如果为t
            if (dfs(board, rows, cols, cells, next_x, next_y))
            {
                return true;
            }
            // 不合格恢复状态，进入本循环中inter下一个数字的尝试
            else
            {
                rows[x][temp - 1] = temp;
                cols[y][temp - 1] = temp;
                cells[(x / 3) * 3 + y / 3][temp - 1] = temp;
                board[x][y] = '.';
            }
        }
        return false;
    }

    // 求交集
    vector<int> getInter(vector<vector<int>>& rows, vector<vector<int>>& cols, vector<vector<int>>& cells, int x, int y) {
        vector<int> tempv;
        for (int i = 0; i < 9; i++)
        {
            if (cols[y][i] && rows[x][i] && cells[(x / 3) * 3 + y / 3][i])
            {
                tempv.push_back(rows[x][i]);
            }
        }
        return tempv;
    }
};

int main37() {
    Solution s;
    vector<vector<char>> test = {
                {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    s.solveSudoku(test);

    return 0;
}