#include<string>
#include<vector>
using namespace std;


class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // 因为是循环选择，所以先考虑两种极端情况，①全都比target大，
        // 即letters[0]>target，return letters[0]
        // 全都比 target小，即letters[-1]<target，return letters[0]
        if (letters[0] > target || letters.back() <= target)
        {
            return letters[0];
        }

        // 二分法使用while循环做，设立left和right，当right和left距离不足1时，
        // 就退出循环，手动判断left和right哪个是需要的数据
        int left = 0, right = letters.size() - 1, middle;
        while (right - left > 1)
        {
            middle = left + (right - left) / 2;
            if (letters[middle] > target)
            {
                right = middle;
            }
            else
            {
                left = middle;
            }
        }
        
        return letters[right];
    }
};