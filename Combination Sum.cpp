class Solution {
public:

    void printS(int ind,vector<vector<int>>&ans,vector<int>&ds,int s,int sum, vector<int>&arr,int n){
    if(ind==n){
        if(sum==s){
            ans.push_back(ds);
        }
        return;
    }

    printS(ind+1,ans,ds,s,sum,arr,n);
    if(s+arr[ind]<=sum){
        s+=arr[ind];
        ds.push_back(arr[ind]);
        printS(ind,ans,ds,s,sum,arr,n);
        ds.pop_back();
    }
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        printS(0,ans,ds,0,target,candidates,candidates.size());
        return ans;
    }
};
