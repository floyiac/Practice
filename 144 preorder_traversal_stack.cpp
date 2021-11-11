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
 * Idea: Use a Stack to simulate the recursion procedure.
 *       The root value enters the stack first and gets popped first.
 *       Then the root->left enters stack.
 *       Last the root->right enters stack.
 *       The pop order is then root left right the pre-order traversal.
 *
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        if(root != NULL){
            stk.push(root);
        }
        while(!stk.empty()){
            TreeNode* target = stk.top();
            stk.pop();
            if(!target){
                continue ;
            }
            else{
                ans.push_back(target->val);
                stk.push(target->right);
                stk.push(target->left);
            }
        }
        return ans;
    }
};