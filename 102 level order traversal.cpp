/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        /**
         * For Level Order Traversal, queue is need instead of stack
         *
         */
        vector<vector<int>> ans;
        if(root == nullptr){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int currlevel = q.size();
            ans.push_back(vector<int>());
            for(int i=1;i<=currlevel;++i){
                TreeNode* tar = q.front();
                q.pop();
                ans.back().push_back(tar->val);
                if(tar->left){q.push(tar->left);};
                if(tar->right){q.push(tar->right);};
            }
        }
        return ans;
    }
};