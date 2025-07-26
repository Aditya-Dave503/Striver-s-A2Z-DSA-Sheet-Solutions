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
        void dfs(TreeNode* root, int sum, int targetSum, vector<vector<int>>&ans, vector<int>&temp){
            if(root==NULL){
                return ;
            }
            sum+=root->val;
            temp.push_back(root->val);
            if(root->left==NULL && root->right==NULL){
                if(sum==targetSum){
                    ans.push_back(temp);
                }
                temp.pop_back();
                return;
            }

            if(root->left){
                dfs(root->left,sum,targetSum,ans,temp);
            }
            if(root->right){
                dfs(root->right,sum,targetSum,ans,temp);
            }
            temp.pop_back();
        }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        int sum=0;
        dfs(root,sum,targetSum,ans,temp);
        return ans;
    }
};
