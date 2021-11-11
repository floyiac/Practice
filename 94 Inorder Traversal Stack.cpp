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
 /**
  * Idea: root enters stack first.
  *       Then root->left enters.
  *       Pop root->left, root
  *       root = root -> right;
  */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans; // store answer
        stack<TreeNode*> stk;
        while(root != nullptr || !stk.empty()){
            while(root != nullptr){
                stk.push(root);
                root = root -> left;
            }
            root = stk.top();
            ans.push_back(root->val);
            stk.pop();
            root = root->right;
        }
        return ans;
    }
};