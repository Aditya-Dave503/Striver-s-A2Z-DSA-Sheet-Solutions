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
    private:
    bool helper(TreeNode* root, long long int mini, long long int maxi){
        if(root==NULL) return 1;
        if(root->val>=maxi || root->val<=mini) return 0;

        return helper(root->left,mini,root->val) && helper(root->right,root->val,maxi);
    }
public:
    bool isValidBST(TreeNode* root) {
       return helper(root, LLONG_MIN, LLONG_MAX);
    }
};
