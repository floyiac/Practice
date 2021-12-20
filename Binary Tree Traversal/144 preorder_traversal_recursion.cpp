class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        preorder(root,ans);
        return ans;
    }
    void preorder(TreeNode* root, vector<int>& res){
        if(!root){

        }
        else{
            res.push_back(root->val);
            preorder(root->left,res);
            preorder(root->right,res);
        }
    }
};
