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
    bool isSymmetric(TreeNode* root) 
    {        
        queue<TreeNode*> leftBucket, rightBucket;
     
        leftBucket.push(root);
        rightBucket.push(root);
        
        while(!leftBucket.empty())
        {
            auto leftNode = leftBucket.front();
            auto rightNode = rightBucket.front();
            leftBucket.pop();
            rightBucket.pop();
            
            if(!leftNode && !rightNode) continue;
            if(!leftNode || !rightNode) return false;
            if(leftNode->val!=rightNode->val) return false;
            
            leftBucket.push(leftNode->left);
            leftBucket.push(leftNode->right);
            
            rightBucket.push(rightNode->right);
            rightBucket.push(rightNode->left);
        }
        
        if(leftBucket.size()!=0 || rightBucket.size()!=0) return false;// one of the side havent fully traversed
        return true;
        
    }
};