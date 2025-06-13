int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at,at+n);
    sort(dt,dt+n);

    int i=0,j=0,cnt=0,maxi=0;

    while(i<n){
        if(at[i]<=dt[j]){
            cnt+=1;
            i+=1;
        }
        else{
            cnt-=1;
            j+=1;
        }
        maxi=max(maxi,cnt);
    }
    return maxi;
}
