class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0;
        int n=nums.size();
        int r=0,l=0;

        while(r<n-1){
            int farthest=0;
            for(int i=l;i<=r;i++){
                farthest=max(i+nums[i],farthest);
            }
            l=r+1;
            r=farthest;
            jumps+=1;
        }
        return  jumps;
    }
};
