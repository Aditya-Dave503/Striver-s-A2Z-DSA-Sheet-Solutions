#include<bits/stdc++.h>
int countSetBits(int n) {
    if(n==0) return 0;
    int x=log2(n);

    int bitsup2x=x*((1<<(x-1)));

    int msbbits=(n-(1<<x))+1;

    int t=countSetBits(n-(1<<x));
    
    return bitsup2x+msbbits+t;
    // Write your code here
}
