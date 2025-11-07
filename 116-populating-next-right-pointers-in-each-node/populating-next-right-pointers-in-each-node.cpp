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
private:
    Node* iterativeSol(Node* root){
        if(!root) return root;
        queue<Node*> todo;
        todo.push(root);
        while(!todo.empty()){
            int n = todo.size();
            Node* leftNode = NULL;
            for(int i = 0 ; i < n ; i++){
                Node* curNode = todo.front();
                todo.pop();
                if(leftNode)leftNode->next =  curNode;
                if(curNode->left) todo.push(curNode->left);
                if(curNode->right)todo.push(curNode->right);
                leftNode = curNode;
            }
        }
        return root;    
    }
public:
    Node* connect(Node* root) {
        if(!root) return root;
        if(root->left) root->left->next = root->right;
        if(root->right && root->next) root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
        return root;
    }
};