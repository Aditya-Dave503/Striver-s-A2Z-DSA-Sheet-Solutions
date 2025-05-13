vector<int> MinimumCoins(int n)
{
    vector<int>ans;
    int arr[9]={1,2,5,10,20,50,100,500,1000};

    for(int i=8;i>=0;i--){
        while(n>=arr[i]){
            n-=arr[i];
            ans.push_back(arr[i]);
        }
    }
    return ans;
}
