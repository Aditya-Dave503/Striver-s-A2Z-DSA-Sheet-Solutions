// User function Template for C++

class Solution {
  public:
  void insert(stack<int>&st,int ele){
      if(st.empty()){
          st.push(ele);
          return;
      }
      
      int toper=st.top();
      st.pop();
      insert(st,ele);
      st.push(toper);
  }
    void Reverse(stack<int> &st) {
        if(st.empty()) return;
        
        int ele=st.top();
        st.pop();
        Reverse(st);
        insert(st,ele);
    }
};
