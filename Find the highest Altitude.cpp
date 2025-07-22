class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int ans=0,sum=0;

        for(int i=0;i<n;i++){
            sum+=gain[i];
            ans=max(ans,sum);
        }
        return ans;
    }
};
