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
        // 定义最终返回值
        vector<TreeNode*> retval;

        // 先排除特殊情况 n = 1
        if (n == 1)
        {
            TreeNode* tree = new TreeNode(1);
            retval.push_back(tree);
            return retval;
        }
        // 否则递归处理
        retval = backTrack(1, n);
        return retval;
    }

    // 递归的子函数内容
    vector<TreeNode*> backTrack(int left, int right) {
        vector<TreeNode*> retval;
        // 在开头定义退出条件，这意味着左子树只有一种情况，就是为空
        // 所以返回一个 vector，里面放着 nullptr
        // 如果返回空vector，则双重循环有一重无法遍历，导致上一层该函数返回值为空vector
        if (left > right)
        {
            retval.push_back(nullptr);
            return retval;
        }
        // 如果left 和 right满足递归的条件按，则进行递归
        for (int i = left; i <= right; i++)
        {
            // 将原始区间分为左右两个子树，进行递归
            vector<TreeNode*> left_nodes = backTrack(left, i - 1);    // 左子树的元素都小于根节点i的值
            vector<TreeNode*> right_nodes = backTrack(i + 1, right);   // 右子树的元素都大于根节点i的值
            // 对返回值进行交叉合并
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