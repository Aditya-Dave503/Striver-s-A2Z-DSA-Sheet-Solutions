class Solution {
public:

    bool f(vector<int>&arr, int m, int k, int mid){
        long long int cnt=0;
        long long int ans=0;

        for(int i=0;i<arr.size();i++){
            if(arr[i]<=mid){
                cnt++;
            }
            else{
                ans+=cnt/k;
                cnt=0;
            }
        }

        ans+=cnt/k;

        return ans>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int mini=*min_element(bloomDay.begin(),bloomDay.end());
        long long int maxi=*max_element(bloomDay.begin(),bloomDay.end());

        long long int low=mini;
        long long int high=maxi;
        long long int ans=-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(f(bloomDay,m,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
