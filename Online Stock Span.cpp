class StockSpanner {
public:
    int ind;
    stack<pair<int,int>>st;
    StockSpanner() {
        ind=-1;
        while(!st.empty()) st.pop();
    }
    
    int next(int price) {
        ind+=1;
        while(!st.empty() && st.top().first<=price) st.pop();
        
        int ans=ind;
        if(st.empty()) ans+=1;
        else ans-=st.top().second;
        st.push({price,ind});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
