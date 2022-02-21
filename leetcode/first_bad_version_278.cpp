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
                right = middle; // ��֤���Ҳ��һ���ǻ��ģ���һ����һ��������������
            }
            // ��������ǻ��ģ���
            else
            {
                left = middle + 1;  // ���middle�Ǻõģ���left�oǰ��һ�������������� ���õ���һ�������ġ���ֱ��������ֻ��һ�����֣����ǳ�ʼ����
            }
        }
        return left;
    }
};