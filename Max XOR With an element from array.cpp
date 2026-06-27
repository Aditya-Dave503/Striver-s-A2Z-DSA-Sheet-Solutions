class Node{
    public:
    Node* child[2];

    Node(){
        child[0]=child[1]=nullptr;
    }
};

class Trie{
    public:
    Node* root=new Node();

    void insert(int num){
        Node* curr=root;

        for(int i=31;i>=0;i--){
            int bit=((num>>i)&1);

            if(!curr->child[bit]){
                curr->child[bit]=new Node();
            }
            curr=curr->child[bit];
        }
    }

    int get(int num){
        Node* curr=root;
        int ans=0;

        for(int i=31;i>=0;i--){
            int bit=((num>>i) & 1);
            if(curr->child[1-bit]){
                ans|=(1<<i);
                curr=curr->child[1-bit];
            }
            else curr=curr->child[bit];
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int q=queries.size();

        sort(nums.begin(), nums.end());

        vector<pair<int,pair<int,int>>> vec(q);

        for(int i=0;i<q;i++){
            vec[i].first=queries[i][1];
            vec[i].second.first=queries[i][0];
            vec[i].second.second=i;
        }

        vector<int>ans(q);
        sort(vec.begin(), vec.end());
        int idx=0;
        Trie t;

        for(int i=0;i<q;i++){
            int mi=vec[i].first;
            int j=vec[i].second.second;
            int xi=vec[i].second.first;

            while(idx<n && nums[idx]<=mi){
                t.insert(nums[idx]);
                idx++;
            }
            if(idx==0) ans[j]=-1;
            else ans[j]=t.get(xi);
        }
        return ans;
    }
};
