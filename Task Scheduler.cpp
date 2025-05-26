class Solution {
public:
// Space Complexity-> O(26) ~= O(1);
// Time Complexity-> O(n+26log26) almost equal to O(n)
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>hash(26,0);

        for(auto it:tasks){
            hash[it-'A']++;
        }

        sort(hash.begin(),hash.end(),greater<int>());

        int ideal=(hash[0]-1)*n;  // number of slots between all max freq. letters

        for(int i=1;i<hash.size();i++){
            ideal=ideal-min(hash[0]-1,hash[i]);
        } 

        return tasks.size()+max(0,ideal);
    }
};
