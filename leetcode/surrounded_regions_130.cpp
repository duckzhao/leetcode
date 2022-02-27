#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // 定义矩阵的shape
        int m = board.size();
        int n = board[0].size();

        // 标记已经遍历过的单元
        set<pair<int, int>> olds;    // 存放的都是 和边界x相连的o
        // 标记当前正在遍历的o
        set<pair<int, int>> nows;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // 如果该字母是o，且不在old中，则dfs
                if (board[i][j] == 'O' && olds.find(pair<int, int>(i, j)) == olds.end())
                {
                    nows.insert(pair<int, int>(i, j));
                    dfs(i, j, board, olds, nows, m, n);
                    int flag = false;

                    // 判断这一次遍历的nows有没有边界，有就全部加入old中，没有就全部设置为x，并清空nows
                    for (auto now : nows)
                    {
                        // 在边界
                        if (now.first == 0 || now.first == m - 1 || now.second == n - 1 || now.second == 0)
                        {
                            flag = true;
                            break;
                        }
                    }
                    if (flag)
                    {
                        // 有就全部加入old中
                        for (auto now : nows)
                        {
                            olds.insert(now);
                        }
                    }
                    else
                    {
                        for (auto now : nows)
                        {
                            board[now.first][now.second] = 'X';
                        }
                    }
                    nows.clear();
                }
            }
        }
    }

    // 遍历该节点连同 的四个节点
    void dfs(int i, int j, vector<vector<char>>& board, set<pair<int, int>>& olds, set<pair<int, int>>& nows, int m, int n) {
        vector<vector<int>> ops = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        for (int k = 0; k < ops.size(); k++)
        {
            vector<int> op = { ops[k][0] + i, ops[k][1] + j };
            // 如果该点符合要求则dfs
            if (op[0] >= 0 && op[0] < m && op[1] >= 0 && op[1] < n && board[op[0]][op[1]] == 'O' && olds.find(pair<int, int>(op[0], op[1])) == olds.end() && nows.find(pair<int, int>(op[0], op[1])) == nows.end())
            {
                nows.insert(pair<int, int>(op[0], op[1]));
                dfs(op[0], op[1], board, olds, nows, m, n);
            }
        }
    }

};

int main130() {
    Solution s;
    vector<vector<char>> board = { {'X', 'X', 'X', 'X'},{'X', 'O', 'O', 'X'},{'X', 'X', 'O', 'X'},{'X', 'O', 'X', 'X' } };
    s.solve(board);
    return 0;
};
