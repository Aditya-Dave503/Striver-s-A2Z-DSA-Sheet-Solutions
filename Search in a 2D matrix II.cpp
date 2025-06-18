class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix[0].size(),m=matrix.size();

        int row=0,col=n-1;

        while(row<m && col>=0){
            if(matrix[row][col]==target)
            return true;
            else if(matrix[row][col]<target)
            row++;
            else col--;
        }
        return false;
    }
};
