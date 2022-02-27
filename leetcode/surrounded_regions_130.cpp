#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // ��������shape
        int m = board.size();
        int n = board[0].size();

        // ����Ѿ��������ĵ�Ԫ
        set<pair<int, int>> olds;    // ��ŵĶ��� �ͱ߽�x������o
        // ��ǵ�ǰ���ڱ�����o
        set<pair<int, int>> nows;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // �������ĸ��o���Ҳ���old�У���dfs
                if (board[i][j] == 'O' && olds.find(pair<int, int>(i, j)) == olds.end())
                {
                    nows.insert(pair<int, int>(i, j));
                    dfs(i, j, board, olds, nows, m, n);
                    int flag = false;

                    // �ж���һ�α�����nows��û�б߽磬�о�ȫ������old�У�û�о�ȫ������Ϊx�������nows
                    for (auto now : nows)
                    {
                        // �ڱ߽�
                        if (now.first == 0 || now.first == m - 1 || now.second == n - 1 || now.second == 0)
                        {
                            flag = true;
                            break;
                        }
                    }
                    if (flag)
                    {
                        // �о�ȫ������old��
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

    // �����ýڵ���ͬ ���ĸ��ڵ�
    void dfs(int i, int j, vector<vector<char>>& board, set<pair<int, int>>& olds, set<pair<int, int>>& nows, int m, int n) {
        vector<vector<int>> ops = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        for (int k = 0; k < ops.size(); k++)
        {
            vector<int> op = { ops[k][0] + i, ops[k][1] + j };
            // ����õ����Ҫ����dfs
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
