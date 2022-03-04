#include<vector>
#include<string>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        return dfs(root);
    }

    vector<string> dfs(TreeNode* node) {
        vector<string> retval;
        // 判断是否到达叶子节点
        if (node->left == nullptr && node->right == nullptr)
        {
            retval.push_back(to_string(node->val));
            return retval;
        }

        vector<string> temp;

        if (node->left != nullptr)
        {
            temp = dfs(node->left);
            combine(node->val, temp, retval);
        }
        if (node->right != nullptr)
        {
            temp = dfs(node->right);
            combine(node->val, temp, retval);
        }
        return retval;
    }

    void combine(int val, vector<string>& temps, vector<string>& retval) {
        for (string temp : temps)
        {
            retval.push_back(to_string(val) + "->" + temp);
        }
    }
};