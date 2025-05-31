class Solution {
public:
    int rob1(vector<int>& nums) {
      int n=nums.size();
      int prev2=0;
      int prev1=nums[0];

      for(int i=1;i<n;i++){
        int pick=nums[i];
        if(i>1) pick+=prev2;
        int notpick=prev1;

        int curi=max(pick,notpick);
        prev2=prev1;
        prev1=curi;
      }
      return prev1;  
    }

    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>t1,t2;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(i!=0) t1.push_back(nums[i]);
            if(i!=n-1) t2.push_back(nums[i]);
        }
        return max(rob1(t1),rob1(t2));
    }
};
