class Solution {
public:
    int countPrimes(int n) {
        
        int count=0;
        vector<bool>vec(n+1,true);

        vec[0]=vec[1]=false;
        for(int i=2;i<n;i++)
        {
            if(vec[i])
            count++;

            for(int j=2*i;j<n;j+=i)
            vec[j]=0;
        }
        return count;
    }
};
