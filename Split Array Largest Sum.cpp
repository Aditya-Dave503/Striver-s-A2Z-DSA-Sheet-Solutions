class Solution {
public:

    bool f(vector<int>&arr,int k, int mid){
        long int sum=0,ans=0;

        for(auto it:arr){
            if(sum+it<=mid){
                sum+=it;
            }
            else{
                ans+=1;
                sum=it;
            }
        }
        return ans+1<=k;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int sum=0,maxi=nums[0],n=nums.size();

        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxi=max(maxi,nums[i]);
        }

        int low=maxi,high=sum,ans=0;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(f(nums,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
