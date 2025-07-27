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
    void dfs(TreeNode* root, vector<string>&ans,string temp){
        temp+=to_string(root->val);

        if(root->right==NULL && root->left==NULL) ans.push_back(temp);
        temp+="->";

        if(root->left) dfs(root->left,ans,temp);
        if(root->right) dfs(root->right,ans,temp);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string temp="";
        dfs(root,ans,temp);
        return ans;
    }
};
