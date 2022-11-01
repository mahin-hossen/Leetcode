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
    void invertTreeHelper(TreeNode* &leftNode, TreeNode* &rightNode)
    {
        if(!leftNode && !rightNode)  return;
        if(leftNode && !rightNode)
        {
            swap(leftNode,rightNode);
            return invertTreeHelper(rightNode->left,rightNode->right);
        }
        if(!leftNode && rightNode)
        {
            swap(leftNode,rightNode);
            return invertTreeHelper(leftNode->left,leftNode->right);

        }   

        swap(leftNode->val,rightNode->val);

        invertTreeHelper(leftNode->left,rightNode->right);
        invertTreeHelper(leftNode->right,rightNode->left);

        return;
    }

    TreeNode* invertTree(TreeNode* root) 
    {
        if(!root) return root;
        invertTreeHelper(root->left,root->right) ;
        return root;

    }
};