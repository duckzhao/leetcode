#include<vector>
#include<set>
#include<string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        bool flag = false;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                flag = dfs(board, word, m, n, i, j);
                if (flag == true)
                {
                    return true;
                }
            }
        }
        return false;
    }

    // index 表示当前回合正在寻找 第几个字母
    bool dfs(vector<vector<char>>& board, string& word, int m, int n, int i, int j) {
        // 判断该点是否越界
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '*')
        {
            return false;
        }
        // 判断该点是否和当前字符相等
        if (board[i][j] != word[0])
        {
            return false;
        }
        // 判断是否是最后一个字符
        if (word.size() == 1)
        {
            return true;
        }
        // 不是最后一个字符就继续dfs
        char c = word[0];
        board[i][j] = '*';
        // 四个dfs
        bool flag = false;
        string s = word.substr(1);  // 截取第一个以后的所有字符串
        flag = dfs(board, s, m, n, i, j + 1) || dfs(board, s, m, n, i, j - 1) || dfs(board, s, m, n, 1 + i, j) || dfs(board, s, m, n, -1 + i, j);

        board[i][j] = c;
        return flag;
    }
};