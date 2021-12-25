class Solution {
public:
    // n is the period

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int target = k%n;
        int index;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            index = (i+target) % n;
            ans[index] = nums[i];
        }
        for(int i=0;i<n;i++){
            nums[i] = ans[i];
        }
    }
};