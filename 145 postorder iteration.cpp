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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*> stk;
        TreeNode* prv = nullptr; //This pointer tracks the previous TreeNode.
        if(root == nullptr){
            return {};
        }
        while(root != nullptr || !stk.empty()){
            while(root != nullptr){
                stk.push(root);
                root = root->left;
            }
            root =stk.top();
            stk.pop();
            if(root->right == nullptr || root->right == prv){
                ans.push_back(root->val);
                prv = root;
                root = nullptr; //Renew the root to be nullptr
            }
            else{
                stk.push(root);
                root = root -> right;
            }
        }
        return ans;
    }
};