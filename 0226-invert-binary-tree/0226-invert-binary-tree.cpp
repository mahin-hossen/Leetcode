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
        if(!leftNode && !rightNode) 
        {
            return;
        }
        if(leftNode && !rightNode)
        {
            // swap(leftNode,rightNode);
            auto dummy = leftNode;
            leftNode = rightNode;
            // rightNode = new TreeNode();
            rightNode = dummy;
            return invertTreeHelper(rightNode->left,rightNode->right);
        }
        if(!leftNode && rightNode)
        {
            auto dummy = rightNode;
            rightNode = leftNode;
            // leftNode = new TreeNode();
            leftNode = dummy;
            // swap(leftNode,rightNode);
            return invertTreeHelper(leftNode->left,leftNode->right);

        }   

        int dummy = leftNode->val;
        leftNode->val = rightNode->val;
        rightNode->val = dummy;

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