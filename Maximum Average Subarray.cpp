class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int ind=0;
        long long int maxi=INT_MIN;
        long long int sum=0;

        for(int i=0;i<k;i++) sum+=nums[i];

        maxi=sum;

        for(int i=k;i<n;i++){
            sum+=nums[i]-nums[i-k];
            maxi=max(maxi,sum);
        }
        return (double)maxi/k;
    }
};
