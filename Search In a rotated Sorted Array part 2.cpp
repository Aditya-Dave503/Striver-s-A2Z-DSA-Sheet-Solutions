class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int start=0,end=n-1;

        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]==target) return 1;
            if(arr[start]==arr[mid] && arr[mid]==arr[end]) {
                start++;
                end--;
                continue;
            }
            if(arr[mid]<=arr[end]){
                if(arr[mid]<=target && target<=arr[end])
                start=mid+1;
                else end=mid-1;
            }
            else{
                if(arr[mid]>=target && arr[start]<=target)
                end=mid-1;
                else start=mid+1;
            }
        }
        return 0;
        
    }
};
