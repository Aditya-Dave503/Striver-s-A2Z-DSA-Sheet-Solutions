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
    void helper(TreeNode* root, int &ans, int sum){
        sum+=1;
        if(root->left==NULL && root->right==NULL){
            ans=min(ans,sum);
            return;
        }

        if(root->left) helper(root->left,ans,sum);
        if(root->right) helper(root->right,ans,sum);
    }
public:
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=INT_MAX;
        int sum=0;

        helper(root,ans,sum);
        return ans;
    }
};
