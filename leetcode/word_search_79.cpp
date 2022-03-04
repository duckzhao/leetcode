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

    // index ��ʾ��ǰ�غ�����Ѱ�� �ڼ�����ĸ
    bool dfs(vector<vector<char>>& board, string& word, int m, int n, int i, int j) {
        // �жϸõ��Ƿ�Խ��
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '*')
        {
            return false;
        }
        // �жϸõ��Ƿ�͵�ǰ�ַ����
        if (board[i][j] != word[0])
        {
            return false;
        }
        // �ж��Ƿ������һ���ַ�
        if (word.size() == 1)
        {
            return true;
        }
        // �������һ���ַ��ͼ���dfs
        char c = word[0];
        board[i][j] = '*';
        // �ĸ�dfs
        bool flag = false;
        string s = word.substr(1);  // ��ȡ��һ���Ժ�������ַ���
        flag = dfs(board, s, m, n, i, j + 1) || dfs(board, s, m, n, i, j - 1) || dfs(board, s, m, n, 1 + i, j) || dfs(board, s, m, n, -1 + i, j);

        board[i][j] = c;
        return flag;
    }
};