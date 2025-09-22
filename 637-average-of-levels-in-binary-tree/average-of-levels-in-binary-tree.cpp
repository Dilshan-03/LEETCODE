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
private:
    vector<double> levelOrderTraversal(TreeNode* root){
        if(!root) return {};
        queue<TreeNode*> todo;
        todo.push(root);
        vector<double> levelOrderAvg;
        while(!todo.empty()){
            int n = todo.size();
            double sum = 0;
            for(int i = 0 ; i < n ; i++){
                TreeNode* curNode = todo.front();
                todo.pop();
                sum += curNode->val;
                if(curNode->left) todo.push(curNode->left);
                if(curNode->right) todo.push(curNode->right);
            }
            levelOrderAvg.push_back(sum / n);   
        }
        return levelOrderAvg;
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        return levelOrderTraversal(root);
    }
};