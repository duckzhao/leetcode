#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        // �������շ���ֵ
        vector<TreeNode*> retval;

        // ���ų�������� n = 1
        if (n == 1)
        {
            TreeNode* tree = new TreeNode(1);
            retval.push_back(tree);
            return retval;
        }
        // ����ݹ鴦��
        retval = backTrack(1, n);
        return retval;
    }

    // �ݹ���Ӻ�������
    vector<TreeNode*> backTrack(int left, int right) {
        vector<TreeNode*> retval;
        // �ڿ�ͷ�����˳�����������ζ��������ֻ��һ�����������Ϊ��
        // ���Է���һ�� vector��������� nullptr
        // ������ؿ�vector����˫��ѭ����һ���޷�������������һ��ú�������ֵΪ��vector
        if (left > right)
        {
            retval.push_back(nullptr);
            return retval;
        }
        // ���left �� right����ݹ��������������еݹ�
        for (int i = left; i <= right; i++)
        {
            // ��ԭʼ�����Ϊ�����������������еݹ�
            vector<TreeNode*> left_nodes = backTrack(left, i - 1);    // ��������Ԫ�ض�С�ڸ��ڵ�i��ֵ
            vector<TreeNode*> right_nodes = backTrack(i + 1, right);   // ��������Ԫ�ض����ڸ��ڵ�i��ֵ
            // �Է���ֵ���н���ϲ�
            for (auto left_node : left_nodes)
            {
                for (auto right_node : right_nodes)
                {
                    TreeNode* node = new TreeNode(i);
                    node->left = left_node;
                    node->right = right_node;
                    retval.push_back(node);
                }
            }
        }

        return retval;
    }
};

int main95() {

    Solution s;
    s.generateTrees(3);
    return 0;
}