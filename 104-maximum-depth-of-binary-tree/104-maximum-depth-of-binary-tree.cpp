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
    int dfs(TreeNode* root, int depth = 0)
    {
        if(root==NULL) return depth;        
        int left = dfs(root->left,depth+1);
        int right = dfs(root->right,depth+1);
        
        return max(left,right);
    }
    int maxDepth(TreeNode* root) 
    {
        return dfs(root);
    }
};