/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    pair<int, int> solve(TreeNode* root, int& ans) {
        if (root == nullptr)
            return {0, 0};

        auto [left_sum, left_count] = solve(root->left, ans);
        auto [right_sum, right_count] = solve(root->right, ans);

        int avg =
            (root->val + left_sum + right_sum) / (left_count + right_count + 1);
        if (root->val == avg)
            ans++;

        return {(root->val + left_sum + right_sum),
                (left_count + right_count + 1)};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};