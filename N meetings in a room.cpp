class Solution {
  public:
  
  static bool comp(pair<int,int>&p1,pair<int,int>&p2){
    return p1.second<p2.second;
  }

    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n=start.size();
        vector<pair<int,int>>vec;
        
        for(int i=0;i<n;i++){
            vec.push_back({start[i],end[i]});
        }
        
        sort(vec.begin(),vec.end(),comp);
        
        int ans=1,lastfree=vec[0].second;
        
        for(int i=1;i<n;i++){
            if(vec[i].first>lastfree){
                ans+=1;
                lastfree=vec[i].second;
            }
        }
        
        return ans;
    }
};
