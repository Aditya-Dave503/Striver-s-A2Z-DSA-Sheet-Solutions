class Solution {
public:

    void findnse(vector<int>&ans, vector<int>&arr){
        stack<int>st;
        int n=arr.size();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i]=n;
            else ans[i]=st.top();
            st.push(i);
        }
    }

    void findpse(vector<int>&ans, vector<int>&arr){
        stack<int>st;
        int n=arr.size();

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i]=-1;
            else ans[i]=st.top();
            st.push(i);
        }
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        long long int mod=1e9+7;
        vector<int>nse(n);
        findnse(nse,arr);
        vector<int>pse(n);
        findpse(pse,arr);

        long long int total=0;
        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            total=(total+(left*right%mod)*arr[i]%mod)%mod;
        }
        return total;
    }
};
