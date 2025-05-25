// User function Template for C++

class Solution {
  public:
    void convertMinToMaxHeap(vector<int> &arr, int N) {
        for(int i=(N-2)/2;i>=0;i--){
            maxheapify(arr,i,N);
        }
    }
    
    void maxheapify(vector<int>&arr,int i,int N){
        int l=2*i+1;
        int r=2*i+2;
        int largest=i;
        
        if(l<N && arr[l]>arr[largest]) largest=l;
        
        if(r<N && arr[r]>arr[largest]) largest=r;
        
        if(largest!=i){
            swap(arr[i],arr[largest]);
            maxheapify(arr,largest,N);
        }
    }
};
