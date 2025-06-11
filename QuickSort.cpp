#include <bits/stdc++.h> 


int f(vector<int>&arr, int low, int high){
    int pivot=arr[low];
    int i=low;
    int j=high;

    while(i<j){
        while(arr[i]<=pivot && i<high){
            i++;
        }

        while(arr[j]>pivot && j>low){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;

}
void qs(vector<int>&arr, int low, int high){
    if(low<high){
        int partition=f(arr,low,high);
        qs(arr,low,partition-1);
        qs(arr,partition+1,high);
    }
}
vector<int> quickSort(vector<int> arr)
{
    qs(arr, 0, arr.size()-1);
    return arr;
}
