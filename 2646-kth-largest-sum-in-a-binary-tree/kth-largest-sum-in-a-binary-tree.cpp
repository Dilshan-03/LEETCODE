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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> levelSum; // store the sum of each level in levelSum
        queue<TreeNode*> todo;
        todo.push(root);
        while(!todo.empty()){
            int size = todo.size();
            long long sum = 0;
            for(int i = 0 ; i < size ; i++){
                TreeNode* cur = todo.front();
                sum += cur->val;
                todo.pop();
                if(cur->left) todo.push(cur->left);
                if(cur->right) todo.push(cur->right);
            }
            levelSum.push_back(sum);
        }
        //sort them up and return the k th largest 
        sort(levelSum.begin() , levelSum.end());
        int n = levelSum.size();
        if(n - k < 0) return -1;
        return levelSum[n - k];
    }
};