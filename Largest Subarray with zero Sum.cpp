/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int n=arr.size();
        vector<int>psum(n+1,0);
        
        for(int i=0;i<n;i++){
            psum[i+1]=psum[i]+arr[i];
        }
        
        unordered_map<int,int>mpp;
        int maxi=0;
        
        for(int i=1;i<=n;i++){
            if(psum[i]==0){
                maxi=max(maxi,i);
            }
            else if(mpp.count(psum[i])){
                maxi=max(maxi,i-mpp[psum[i]]);
            }
            else mpp[psum[i]]=i;
        }
        return maxi;
    }
};
