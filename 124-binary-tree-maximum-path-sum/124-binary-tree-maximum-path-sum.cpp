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
    int pathSum;
    int maxChainSum(TreeNode* root)
    {
        if(root==NULL) return 0;
        int L = maxChainSum(root->left);
        int R = maxChainSum(root->right);
        pathSum = max(L+R+root->val,pathSum);
        return max(0,max(L,R)+root->val);
    }
    int maxPathSum(TreeNode* root)
    {        
        pathSum = INT_MIN;
        maxChainSum(root);
        return pathSum;
    }
};