// User function template for C++

class Solution {
  public:
  
    bool f(vector<int>&arr,int k, int mid){
        long int sum=0,ans=1;
        
        for(auto it:arr){
            if(sum+it<=mid){
                sum+=it;
            }
            else{
                ans+=1;
                sum=it;
            }
        }
        
        return ans<=k;
    }
    
    
    int minTime(vector<int>& arr, int k) {
        int sum=0,maxi=0;
        
        for(auto it:arr){
            sum+=it;
            maxi=max(maxi,it);
        }
        
        int low=maxi,high=sum,ans=0;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(f(arr,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
