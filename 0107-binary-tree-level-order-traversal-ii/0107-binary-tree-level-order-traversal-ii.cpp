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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        stack<vector<int>> st;
        while (!q.empty()) {
            int sz = q.size();
            vector<int> temp;
            while (sz--) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
                temp.push_back(node->val);
            }
            st.push(temp);
        }
        vector<vector<int>> ans;
        while (!st.empty()) {
            auto vec = st.top();
            st.pop();
            ans.push_back(vec);
        }
        return ans;
    }
};