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
        
        queue<pair<TreeNode*,int>> bucket;
        int depthCount;
        bucket.push({root,1});        
        
        while(!bucket.empty())
        {
            auto top = bucket.front();
            bucket.pop();
            
            auto node = top.first;
            auto depth = top.second;
            depthCount = max(depthCount,depth);
            
            if(node->left) bucket.push({node->left,depth+1});
            if(node->right) bucket.push({node->right,depth+1});
        }
        return depthCount;
        
    }
};