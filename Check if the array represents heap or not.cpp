
class Solution {
  public:
    bool isMaxHeap(int arr[], int n) {
        for(int i=0;i<n;i++){
            int ind=i+1;
            if(arr[ind*2-1]>arr[ind-1] || arr[ind*2]> arr[ind-1])
            return 0;
        }
        return 1;
    }
};
