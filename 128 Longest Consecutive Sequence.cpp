class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //创建哈希表 注意unordered_set 中没有重复数字
        unordered_set<int> hashmap;
        for(const int& num : nums){
            hashmap.insert(num);
        }

        int ans = 0;
        //注意到连续数字段的首个数字前一位必定没有<key,value> pair 存在
        //连续数字段中间位置的数前一位都有pair存在
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