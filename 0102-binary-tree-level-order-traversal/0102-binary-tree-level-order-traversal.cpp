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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        queue<pair<TreeNode*,int>> bucket;
        vector<vector<int>> order;

        if(!root) return order;        

        bucket.push({root,0});
        // order.push_back({root->val});

        while(!bucket.empty())
        {
            auto top = bucket.front();
            bucket.pop();
            auto node = top.first;
            auto cnt = top.second;


            if(node->left) bucket.push({node->left,cnt+1});
            if(node->right) bucket.push({node->right,cnt+1});

            if(order.size()<=cnt) order.push_back({node->val});
            else order[cnt].push_back(node->val);
        }

        return order;
    }
};