#include<vector>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // �����������
        if (isConnected.size() == 1)
        {
            return 1;
        }

        // ����ֵ
        int count = 0;

        int n = isConnected.size();
        // ����dfs����ÿ������
        for (int i = 0; i < n; i++)
        {
            if (isConnected[i][i] == 1)
            {
                count++;
                // ���Խ���Ԫ����0
                isConnected[i][i] = 0;
                dfs(i, n, isConnected);
            }
        }
        return count;
    }

    // ʹ��dfs���� loc ����һ�У�loc+1��n-1] ����һ�� [0, loc-1]
    void dfs(int loc, int n, vector<vector<int>>& isConnected) {
        // ����loc��һ��,i������λ��
        for (int i = loc + 1; i < n; i++)
        {
            // ����� ���к� ���г������ӣ���������еĶԽ�����Ϊ0
            if (isConnected[loc][i] == 1)
            {
                isConnected[loc][i] = 0;
                isConnected[i][i] = 0;
                // ��ȱ���
                dfs(i, n, isConnected);
            }
        }

        // ����loc��һ��
        for (int j = 0; j < loc; j++)
        {
            // ����� ���к� ���г������ӣ���������еĶԽ�����Ϊ0
            if (isConnected[j][loc] == 1)
            {
                isConnected[j][loc] = 0;
                isConnected[j][j] = 0;
                // ��ȱ���
                dfs(j, n, isConnected);
            }
        }
    }
};