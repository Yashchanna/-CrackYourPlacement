class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> level;
            queue<TreeNode*> q2;

            while (!q.empty()) {
                TreeNode* curr = q.front();
                q.pop();

                level.push_back(curr->val);

                if (curr->left) q2.push(curr->left);
                if (curr->right) q2.push(curr->right);
            }

            ans.push_back(level);

            // Move q2 to q
            while (!q2.empty()) {
                TreeNode* a = q2.front();
                q.push(a);
                q2.pop();
            }
        }

        return ans;
    }
};
