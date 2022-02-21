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

        // i 为迭代次数
        for (int i = 0; i < size; i++)
        {
            int temp_sum = numbers[answer[0]] + numbers[answer[1]];
            // 如果相等直接return当前的两个索引位置即可
            if (temp_sum == target)
            {
                // return前满足 1索引开始
                answer[0] += 1;
                answer[1] += 1;
                // return answer; 最好别在for里面return，别在if的分支里return
                break;
            }
            // 如果当前sum小于target，则begin索引++
            else if (temp_sum < target)
            {
                answer[0] += 1;
            }
            // 如果当前sum大于target，则end索引--
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