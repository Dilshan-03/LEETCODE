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
    int mod = (int)1e9 + 7;
    long long findTotalSum(TreeNode* root){
        if(!root) return 0;
        long long sum = 0;
        sum += root->val;
        sum += findTotalSum(root->left);
        sum += findTotalSum(root->right);
        return sum;
    }
    long long helper(TreeNode* root , long long& maxProduct , long long total){
        if(!root) return 0;
        long long sum = 0;
        sum += root->val;
        sum += helper(root->left , maxProduct , total);
        sum += helper(root->right , maxProduct , total);
        long long rem = total - sum;
        long long curProduct = sum * rem;
        maxProduct = max(maxProduct  , curProduct);
        return sum;
    }
public:
    int maxProduct(TreeNode* root) {
        long long total = findTotalSum(root);
        long long max = 0;
        helper(root , max ,  total);
        return max % mod;
    }
};