/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        //If root is NULL, return
        if(!root)
            return NULL;
        
        //If any one node found, return the node
        if(root == p || root == q)
            return root;
        
        //Recurse on left and right node
        TreeNode* left = lowestCommonAncestor(root->left, p,q);
        TreeNode* right = lowestCommonAncestor(root->right, p,q);
        
        //If both left and right recursion returned NULL, return NULL.
        if( !left && !right)
            return NULL;
        
        //If both left and right recursion returned not-null, return root.
        if(left && right)
            return root;
        
        //If only left pointer is not null, return left
        if(left)
            return left;
        
        //Else if only right pointer is not null, return right
        return right;
        
    }
};
