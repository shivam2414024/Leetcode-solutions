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
    void inorder(TreeNode* root, vector<int>& nums) {
        if (root == nullptr)
            return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    void solve(TreeNode* root, vector<int>& nums, int& i) {
        if (root == nullptr)
            return;
        solve(root->left, nums, i);
        if (root->val == nums[i])
            i++;
        else {
            root->val = nums[i];
            i++;
        }
        solve(root->right, nums, i);
    }
    void recoverTree(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        sort(nums.begin(), nums.end());
        int i = 0;
        solve(root, nums, i);
    }
};