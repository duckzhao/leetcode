#include<vector>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // ���� �ĸ��ڵ�Ĳ���·��
        vector<vector<int>> ops = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
        
        // �������·��
        int max_area = 0;

        // ��ʼ����ÿ���ڵ�
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                vector<int> next = { i, j };

                // �������ڵ���1�ͷŽ�ȥ�ж�
                if (grid[next[0]][next[1]] == 1)
                {
                    grid[next[0]][next[1]] = 0; // �Ѿ�����ĵ�����Ϊ0����ֹ���α���
                    int temp = getArea(next, grid, ops);
                    max_area = temp > max_area ? temp : max_area;
                }
            }
        }
        return max_area;
    }

    // �����Ӻ��������ڴ�ĳ���ڵ����Ѱ������ĸ��ڵ��Ƿ�����½��
    int getArea(vector<int> middle, vector<vector<int>>& grid, vector<vector<int>>& ops) {
        // ��������ڵ����ڵĵ����С
        int area = 1;
        grid[middle[0]][middle[1]] = 0; // �Ѿ�����ĵ�����Ϊ0����ֹ���α���

        // Ѱ���ĸ��ڵ��Ƿ�Ϊ����
        for (auto op : ops )
        {
            // �õ���һ�����������
            vector<int> next = { middle[0] + op[0], middle[1] + op[1] };
            // ���next�������߽���Ϊ1�ű���
            if (next[0] >= 0 && next[1] >= 0 && next[0] < grid.size() && next[1] < grid[0].size() && grid[next[0]][next[1]] == 1)
            {
                area += getArea(next, grid, ops);   // �����һ��������������
            }
            else
            {
                continue;
            }
            
        }
        // ��û�õݹ��ˣ�˵����������ߵ�ͷ�ˣ����ص�ǰ�����
        return area;
    }
};

int main695() {
    Solution s;
    vector<vector<int>> v = { {0, 0, 0, 0, 0, 0} };
    s.maxAreaOfIsland(v);
    return 0;
}