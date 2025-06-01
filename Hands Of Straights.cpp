class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int g) {
        int n=hand.size();
        if(n%g) return 0;
        map<long long,long long>mpp;
        for(auto it:hand) mpp[it]+=1;

        priority_queue<long long int,vector<long long>,greater<long long>>pq;
        for(auto it:mpp) pq.push(it.first);

        while(!pq.empty()){
            long long int first=pq.top();

            for(long long int i=first;i<first+g;i++){
                if(mpp.find(i)==mpp.end()) return 0;
                mpp[i]-=1;

                if(mpp[i]==0){
                    if(i!=pq.top()) return false;
                    pq.pop();
                }
                
            }
        }
        return 1;
    }
};
