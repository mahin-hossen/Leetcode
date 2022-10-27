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
    vector<int> inorderTraversal(TreeNode* root) 
    {       
        vector<int>order;
        stack<TreeNode*> bucket; 
        
        while(root || !bucket.empty())
        {
            while(root)
            {
                bucket.push(root);
                root=root->left;                
            }
            root = bucket.top();
            bucket.pop();
            order.push_back(root->val);
            root=root->right;            
        }
        return order;        
    }
};