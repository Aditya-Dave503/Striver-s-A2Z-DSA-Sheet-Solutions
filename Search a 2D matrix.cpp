class Solution {
public:

    bool f(vector<int>&arr,int k){
        int low=0,high=arr.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==k) return 1;
            else if(arr[mid]>k) high=mid-1;
            else low=mid+1;
        }
        return 0;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int low=0,high=n-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(target>=matrix[mid][0] && target<=matrix[mid][m-1]){
                return f(matrix[mid],target);
            }
            else if(target>matrix[mid][0] && target>matrix[mid][m-1]){
                low=mid+1;
            }
            else high=mid-1;
        }
        return 0;
    }
};
