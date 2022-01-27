/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr){
            return root; // empty tree
        }
        queue<Node*> que;
        que.emplace(root);
        root->next = nullptr;
        while(!que.empty()){
            int size = que.size();
            for(int i=0;i<size;i++){
                Node* a = que.front();
                que.pop();
                if(i<size -1){
                    a->next = que.front();
                    if(a->left != nullptr){
                        que.emplace(a->left);
                    }
                    if(a->right != nullptr){
                        que.emplace(a->right);
                    }
                }
                else{
                    a->next = NULL;
                    if(a->left != nullptr){
                        que.emplace(a->left);
                    }
                    if(a->right != nullptr){
                        que.emplace(a->right);
                    }
                }
            }
        }
        return root;
    }
};