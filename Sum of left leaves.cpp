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
    void dfs(TreeNode* root, TreeNode* parent,long long int &sum){
        if(root->right==NULL && root->left==NULL){
            if(parent->left==root){
                sum+=root->val;
            }
        }

        if(root->left) dfs(root->left,root,sum);
        if(root->right) dfs(root->right,root, sum);
    }
    
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return 0;

        long long int sum=0;
        if(root->left)
            dfs(root->left,root,sum);
        if(root->right){
            dfs(root->right,root,sum);
        }
        return sum;
    }
};
