class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> store;
        int n = s.size();
        int rk = -1, ans = 0;
        for(int i =0; i<n;i++){
            if( i != 0 ){
                store.erase(s[i-1]);
            }
            while(rk+1 < n && !store.count(s[rk+1])){
                store.insert(s[rk+1]);
                rk++;
            }
            ans = max(ans,rk+1-i);
        }
        return ans;
    }
};