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
        if(root==NULL) return root;

        int value=root->val;
        if(p->val>value && q->val>value) return lowestCommonAncestor(root->right,p,q);
        if(p->val<value && q->val<value) return lowestCommonAncestor(root->left,p,q);
        return root;
    }
};
