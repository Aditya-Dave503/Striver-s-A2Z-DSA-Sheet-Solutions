class Solution {
  public:
  
    bool f(vector<int>&arr,int k, double mid){
        int ans=0;
        
        for(int i=1;i<arr.size();i++){
            int d=arr[i]-arr[i-1];
            ans+=(int)(d/mid);
        }
        return ans<=k;
    }
    
    
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n=stations.size();
        double low=0,high=stations[n-1]-stations[0], ans=0;
        
        while(high-low>1e-6){
            double mid=(high+low)/2.0;
            
            if(f(stations,k, mid)){
                ans=mid;
                high=mid;
            }
            else low=mid;
        }
        return ans;
    }
};
