class Solution {
public:

long long int f(vector<int>&piles,int mid){
    long long int totsum=0;
    for(auto it:piles){
        totsum+=((it+mid-1)/mid);
    }
    return totsum;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int maxi=*max_element(piles.begin(),piles.end());
        long long int s=1,e=maxi,ans=0;

        while(s<=e){
            long long int mid=s+(e-s)/2;
            long long int t=f(piles,mid);
            if(t<=h){
                ans=mid;
                e=mid-1;
            }
            else if(t>h) s=mid+1;
        }
        return ans;
    }
};
