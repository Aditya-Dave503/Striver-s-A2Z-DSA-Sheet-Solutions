class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mpp;

        for(auto it:s){
            mpp[it]++;
        }

        for(auto it:mpp) pq.push({it.second,it.first});
        string ans="";
        while(!pq.empty()){
            auto[cnt,ch]=pq.top();
            pq.pop();
            for(int i=0;i<cnt;i++) ans+=ch;
        }
        return ans;
    }
};
