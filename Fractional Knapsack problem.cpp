#include <bits/stdc++.h> 
bool comp(pair<int,int>p1,pair<int,int>p2){
    if((double)p1.second/p1.first>=(double)p2.second/p2.first) return 1;
    return 0;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(),items.end(),comp);
    double totalvalue=0;

    for(auto it:items){
        if(it.first<=w){
            totalvalue+=it.second;
            w-=it.first;
        }
        else{
            double perweight=((double)it.second/it.first)*w;
            totalvalue+=perweight;
            break;
        }
    }
    return totalvalue;
}
