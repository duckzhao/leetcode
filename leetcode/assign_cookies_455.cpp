#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

// 贪心思想，先满足能满足的少饼干的情况，因为满足大的一定能满足小的
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 先对所有孩子的胃口和饼干大小进行排序-升序
        // 从最小的胃口i和饼干j开始比较，当饼干大小满足孩子胃口时，i++，j++
        // 否则 j++，直到 i 和 j跳出size为止
        sort(g.begin(), g.end());   // sort默认升序
        sort(s.begin(), s.end());
        int i = 0, j = 0, count = 0;
        while ((i < g.size()) && (j < s.size()))
        {
            // 当孩子胃口能满足，都++
            if (g[i] <= s[j])
            {
                count++;
                i++;
                j++;
            }
            // 否则换下一块更大的饼干试试
            else
            {
                j++;
            }
        }
        return count;
    }
};