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
    TreeNode* solve(int n, vector<int>& nums, int& i, int bound) {
        if (i >= n || nums[i] >= bound) {
            return NULL;
        }
        TreeNode* root = new TreeNode(nums[i++]);
        root->left = solve(n, nums, i, root->val);
        root->right = solve(n, nums, i, bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        int i = 0;
        return solve(n, preorder, i, INT_MAX);
    }
};