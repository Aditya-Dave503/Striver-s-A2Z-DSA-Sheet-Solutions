int findKRotation(vector<int> &nums){
    // Write your code here.  
    int n=nums.size();
        int start=0,end=n-1;
        int ans=1e9,ind=-1;

        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[start]<=nums[end]){
                if(nums[start]<ans){
                    ans=nums[start];
                    ind=start;
                }
                break;
            }

            if(nums[start]<=nums[mid]){
                if(nums[start]<ans){
                    ans=nums[start];
                    ind=start;
                }
                start=mid+1;
            }
            else{
                end=mid-1;
                if(nums[mid]<ans){
                    ans=nums[mid];
                    ind=mid;
                }
            }
        }
        return ind;  
}
