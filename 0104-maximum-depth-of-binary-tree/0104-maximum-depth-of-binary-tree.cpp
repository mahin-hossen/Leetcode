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
    int maxDepth(TreeNode* root)
    {        
        //MC 0(H) 
        //TC 0(N)
        if(!root) return 0;
        
        auto left = maxDepth(root->left);
        auto right = maxDepth(root->right);
        
        return max(left+1,right+1);
        
    }
};