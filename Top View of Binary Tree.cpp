/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        if(root==NULL) return ans;
        map<int,int>mpp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node* node=it.first;
            int x=it.second;
            
            if(mpp.find(x)==mpp.end()) mpp[x]=node->data;
            
            if(node->left) q.push({node->left,x-1});
            if(node->right) q.push({node->right,x+1});
        }
        
        
        for(auto it:mpp) ans.push_back(it.second);
        return ans;
    }
};
