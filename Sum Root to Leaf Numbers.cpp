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
    void dfs(TreeNode* root, long long int &sum, int number){
        if(root==NULL) return;

        number=number*10+root->val;
        if(root->left==NULL && root->right==NULL){
            sum+=number;
            return;
        }

        if(root->left) dfs(root->left,sum,number);
        if(root->right) dfs(root->right,sum,number);
    }

public:
    int sumNumbers(TreeNode* root) {
        long long int sum=0,number=0;

        dfs(root,sum,number);
        return sum;
    }
};
