using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int version) {
    return 0;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n, middle;
        while (right != left)
        {
            middle = left + (right - left) / 2;
            if (isBadVersion(middle))
            {
                right = middle; // 保证最右侧的一定是坏的，即一定有一个坏的在区间内
            }
            // 如果他不是坏的，则
            else
            {
                left = middle + 1;  // 如果middle是好的，则left給前推一个，保持区间是 【好的下一个，坏的】，直到区间内只有一个数字，就是初始坏的
            }
        }
        return left;
    }
};