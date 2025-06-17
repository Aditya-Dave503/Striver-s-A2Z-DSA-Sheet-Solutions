class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int i=0,j=0;
        int n=(n1+n2);
        int ind1=n/2,ind2=n/2-1;
        int cnt=0,ele1=-1,ele2=-1;

        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                if(cnt==ind1) ele1=nums1[i];
                if(cnt==ind2) ele2=nums1[i];
                cnt++;
                i++;
            }
            else{
                if(cnt==ind1) ele1=nums2[j];
                if(cnt==ind2) ele2=nums2[j];
                cnt++;
                j++;
            }
        }

        while(i<n1){
                if(cnt==ind1) ele1=nums1[i];
                if(cnt==ind2) ele2=nums1[i];
                cnt++;
                i++;
        }

        while(j<n2){
            if(cnt==ind1) ele1=nums2[j];
            if(cnt==ind2) ele2=nums2[j];
            cnt++;
            j++;
        }

        if(n%2){
            return ele1;
        }
        return (double)((double)ele1+ele2)/2.0;
    }
};
