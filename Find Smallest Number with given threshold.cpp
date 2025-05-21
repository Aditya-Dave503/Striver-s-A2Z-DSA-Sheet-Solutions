class Solution {
public:

long long int f(vector<int>&nums,long long int mid){
    long long int sum=0;
    for(auto it:nums){
        sum+=((it+mid-1)/mid);
    }
    return sum;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long int maxi=*max_element(nums.begin(),nums.end());
        long long int s=1,e=maxi,ans=-1;

        while(s<=e){
            long long int mid=s+(e-s)/2;
            if(f(nums,mid)<=threshold){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};
