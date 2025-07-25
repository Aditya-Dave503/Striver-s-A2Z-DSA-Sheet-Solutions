class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>>vec(n);

        for(int i=0;i<n;i++){
            vec[i].first=capital[i];
            vec[i].second=profits[i];
        }

        sort(vec.begin(),vec.end(),[](pair<int,int>p1,pair<int,int>p2){
            if(p1.first<p2.first) return true;
            if(p1.first==p2.first) return p1.second>p2.second;

            return false;
        });

        priority_queue<int>pq;
        int j=0;

        for(int i=0;i<min(n,k);i++){
            while(j<n && vec[j].first<=w){
                pq.push(vec[j].second);
                j++;
            }

            if(pq.empty()) break;

            w+=pq.top();
            pq.pop();
        }

        return w;
    }
};
