class Solution {
public:

    bool f(vector<int>&arr,int mid,int days){
        int sum=0,ans=0;

        for(auto it:arr){
            if((sum+it)<=mid){
                sum+=it;
            }
            else{
                ans+=1;
                sum=it;
            }
        }
        ans+=1;

        return ans<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0,maxi=0;

        for(auto it:weights){
            sum+=it;
            maxi=max(maxi,it);
        }

        int low=maxi,high=sum;
        int ans=0;

        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(f(weights,mid,days)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
