#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // auto pBegin = numbers.begin();
        // vector<int>::iterator pBegin = numbers.begin();
        // vector<int>::iterator pEnd = numbers.end();

        int size = numbers.size();

        vector<int> answer;
        int begin = 0;
        int end = size - 1;
        answer.push_back(begin);
        answer.push_back(end);

        // i Ϊ��������
        for (int i = 0; i < size; i++)
        {
            int temp_sum = numbers[answer[0]] + numbers[answer[1]];
            // ������ֱ��return��ǰ����������λ�ü���
            if (temp_sum == target)
            {
                // returnǰ���� 1������ʼ
                answer[0] += 1;
                answer[1] += 1;
                // return answer; ��ñ���for����return������if�ķ�֧��return
                break;
            }
            // �����ǰsumС��target����begin����++
            else if (temp_sum < target)
            {
                answer[0] += 1;
            }
            // �����ǰsum����target����end����--
            else if (temp_sum > target)
            {
                answer[1] -= 1;
            }
        }
        return answer;
    }
};

int main167() {
    Solution S;
    vector<int> v = {2,7,11,15};
    S.twoSum(v, 9);

    return 0;
}