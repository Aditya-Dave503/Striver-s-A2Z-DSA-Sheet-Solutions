/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */

void sorted(stack<int>&st,int n){
    if(n<=1) return;
    
    int ele=st.top();
    st.pop();
    sorted(st,n-1);
    stack<int>dummy;
    
    while(!st.empty() && st.top()>ele){
        dummy.push(st.top());
        st.pop();
    }
    st.push(ele);
    
    while(!dummy.empty()){
        st.push(dummy.top());
        dummy.pop();
    }
    return;
    
}
void SortedStack ::sort() {
    // Your code here
    sorted(s,s.size());
}
