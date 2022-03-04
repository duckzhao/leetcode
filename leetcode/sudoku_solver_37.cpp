#include<vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // ÿһ�л�ȱʲô��ÿһ�л�ȱʲô����ÿһ��cell��ȱʲô��
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

        // ����board����ÿһ���е�������Ϊ0��ʣ�µķ�0����ȱ����
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char c = board[i][j];
                if (c != '.')
                {
                    int temp = c - '0'; // �õ�c��ʾ������
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
            // ����ҵ����һ��λ�ã���û��.�Ļ���˵����������ˣ�ֱ��return t
            if (x == 9)
            {
                return;
            }
        }
        dfs(board, rows, cols, cells, x, y);
    }

    bool dfs(vector<vector<char>>& board, vector<vector<int>>& rows, vector<vector<int>>& cols, vector<vector<int>>& cells, int x, int y) {
        // �ж�
        vector<int> inter = getInter(rows, cols, cells, x, y);
        if (inter.empty())
        {
            return false;
        }
        // ����һ��return t������ x y�������һ������inter��Ϊ��
        if (x == 8 && y == 8)
        {
            board[8][8] = inter[0] + '0';
            return true;
        }

        // �������ѡ����
        for (int i = 0; i < inter.size(); i++)
        {
            // ����תΪchar
            int temp = inter[i];    // �����������
            char c = inter[i] + '0';
            board[x][y] = c;
            // ��rows���� ��ǵ�ǰ���õ������
            rows[x][temp - 1] = 0;
            cols[y][temp - 1] = 0;
            cells[(x / 3) * 3 + y / 3][temp - 1] = 0;
            // ������һ��dfsʱ��ֻ���� . �ĸ��Ӳ��ܽ�ȥ
            int next_y = y + 1;
            int next_x = x;
            while (true)
            {
                if (next_y == 9)
                {
                    next_y = 0;
                    next_x++;
                }
                // ����ҵ����һ��λ�ã���û��.�Ļ���˵����������ˣ�ֱ��return t
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
            // ���Ϊt
            if (dfs(board, rows, cols, cells, next_x, next_y))
            {
                return true;
            }
            // ���ϸ�ָ�״̬�����뱾ѭ����inter��һ�����ֵĳ���
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

    // �󽻼�
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