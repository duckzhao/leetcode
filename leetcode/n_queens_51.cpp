#include<vector>
#include<string>
#include<set>
#include<cmath>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> retval;
        vector<string> board(n, string(n, '.'));
        vector<int> rows;
        vector<int> cols;
        dfs(retval, board, rows, cols, n, 0, 0);
        return retval;
    }

    void dfs(vector<vector<string>>& retval, vector<string>& board, vector<int>& rows, vector<int>& cols, int n, int x, int y) {
        if (n == 0)
        {
            retval.push_back(board);
            return;
        }
        if (y == board.size())
        {
            y = 0;
            x++;
        }
        if (x == board.size())
        {
            return;
        }
        // 开始迭代
        while (x < board.size())
        {
            // 判断 x 和 y 合格否
            if (judge(rows, cols, x, y))
            {
                // 标记
                rows.push_back(x);
                cols.push_back(y);
                board[x][y] = 'Q';
                dfs(retval, board, rows, cols, n - 1, x, y + 1);
                // 复原
                rows.pop_back();
                cols.pop_back();
                board[x][y] = '.';
            }
            // 不满足的话，继续试下一个点
            y++;
            if (y == board.size())
            {
                y = 0;
                x++;
            }
        }
    }

    // 判断当前位置是否能放皇后
    bool judge(vector<int>& rows, vector<int>& cols, int x, int y) {
        int size = rows.size();
        for (int i = 0; i < size; i++)
        {
            if (rows[i] == x || cols[i] == y || abs(rows[i] - x) == abs(cols[i] - y))
            {
                return false;
            }
        }
        return true;
    }
};

int main51() {
    Solution s;
    s.solveNQueens(1);

    return 0;
}