class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0,one=0,two=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zero+=1;
            if(nums[i]==1) one+=1;
            if(nums[i]==2) two+=1;
        }
        
        int i=0,count=0;
        while(count<zero){
            nums[i]=0;
            i++;
            count++;
        }
        count=0;
        while(count<one){
            nums[i]=1;
            i++;
            count++;
        }
        count=0;
        while(count<two){
            nums[i]=2;
            i++;
            count++;
        }
    }
};
