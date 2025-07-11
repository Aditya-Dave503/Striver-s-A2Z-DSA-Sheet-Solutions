class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        int leftmax=0,rightmax=0;
        long int total=0;

        while(l<r){
            if(height[l]<=height[r]){
                if(height[l]<leftmax) total+=leftmax-height[l];
                else leftmax=height[l];
                l++;
            }
            else{
                if(height[r]<rightmax) total+=rightmax-height[r];
                else rightmax=height[r];
                r-=1;
            }
        }
        return total;
    }
};
