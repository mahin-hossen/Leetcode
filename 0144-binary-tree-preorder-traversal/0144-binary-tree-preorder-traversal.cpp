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
    void traverse(TreeNode* root, vector<int> &order)
    {
        if(!root) return;
        
        order.push_back(root->val);
        traverse(root->left,order);
        traverse(root->right,order);
        
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) 
    {
        if(!root) return {};
        
        vector<int> order;        
        stack<TreeNode*> bucket;        
        bucket.push(root);
        /*
            1
           2 3
        */
        while(!bucket.empty())
        {   
            if(bucket.top()==NULL)
            {
                bucket.pop();
                continue;
            }
            auto front = bucket.top();
            bucket.pop();
            
            order.push_back(front->val);
            bucket.push(front->right);
            bucket.push(front->left);            
        }
        
        
        
        
//         order.push_back(root->val);
        
//         bucket.push(root);
//         traverse(root,order);
        return order;
    }
};