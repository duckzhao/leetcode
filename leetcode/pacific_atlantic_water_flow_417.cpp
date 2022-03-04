#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // ��po��ao�ֱ� �������Ͻ������������������ĵ���Ϊ1
        // ����������������ӣ�������Ϊ2����˵���õ��ܹ����߶�����
        int m = heights.size(), n = heights[0].size();
        // ���巵��ֵ
        vector<vector<int>> retval;
        // ����Ƿ�po��ao�߽��ܵ���õ�
        vector<vector<int>> po_arrive(m, vector<int>(n, 0));
        vector<vector<int>> ao_arrive(m, vector<int>(n, 0));
        // �������������߽磬i��ʾ����
        for (int i = 0; i < n; i++)
        {
            dfs(0, i, m, n, po_arrive, heights);
            dfs(m - 1, i, m, n, ao_arrive, heights);
        }
        // �������������߽磬i��ʾ����
        for (int i = 0; i < m; i++)
        {
            dfs(i, 0, m, n, po_arrive, heights);
            dfs(i, n - 1, m, n, ao_arrive, heights);
        }
        // �����������󶼸��м������Ժ��൱�ڰ���������������ܹ���������cell
        // �������˱�ǣ������Щ��ǣ������Ϊ2����˵���Ǵ�
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (po_arrive[i][j] + ao_arrive[i][j] == 2)
                {
                    retval.push_back({ i, j });
                }
            }
        }
        return retval;
    }

    // ��po�߽翪ʼ���м���б���
    void dfs(int i, int j, int m, int n, vector<vector<int>>& arrived, vector<vector<int>>& heights) {
        // �ȶ��ͽ����ĵ���б��
        arrived[i][j] = 1;

        vector<vector<int>> ops = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        for (auto op : ops)
        {
            int newx = op[0] + i;
            int newy = op[1] + j;
            // �ж���һ�����Ƿ�Խ��
            if (newx < 0 || newy < 0 || newx >= m || newy >= n)
            {
                continue;
            }
            // ��Խ��Ļ��ж��µ��height�Ƿ����ij��
            if (heights[i][j] > heights[newx][newy])
            {
                continue;
            }
            // �µ�߶�Ҳ����Ļ��жϸõ��Ƿ��Ѿ������
            if (arrived[newx][newy] != 0)
            {
                continue;
            }
            // ����������û����ǣ����Ǹõ㲢�Ըõ����dfs
            dfs(newx, newy, m, n, arrived, heights);
        }
    }
};

int main417() {

    Solution s;
    vector<vector<int>> heights = { {1,1},{1,1},{1,1} };
    s.pacificAtlantic(heights);
    return 0;
}