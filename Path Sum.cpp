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
        bool dfs(TreeNode* root, int sum, int target){
            if(root==NULL){
                return 0;
            }
            sum+=root->val;

            if(root->left==NULL && root->right==NULL){
                if(sum==target) return 1;
                return 0;
            }

            bool f1=0,f2=0;
            if(root->left){
                f1=dfs(root->left,sum,target);
            }
            if(root->right){
                f2=dfs(root->right,sum,target);
            }
            return f1| f2;
        }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        int sum=0;
        return dfs(root,sum,targetSum);
    }
};
