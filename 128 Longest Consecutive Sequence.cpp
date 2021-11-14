class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashmap;
        for(const int& num : nums){
            hashmap.insert(num);
        }

        int ans = 0;

        for(const int& num : hashmap){
            if(!hashmap.count(num-1)){
                int curr = num;
                int length = 1;
                while(hashmap.count(curr+1)){
                    curr += 1;
                    length += 1;
                }
                ans = max(ans,length);
            }
        }
        return ans;
    }
};