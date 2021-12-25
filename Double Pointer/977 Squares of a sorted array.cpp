
class Solution {
public:
//  Solution 1
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        for(int it : nums){
            ans.push_back(it * it);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }

    //Solution 2
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int pos = n-1;
        int left = 0;
        int right = pos;
        for(int i=0;i<n;i++){
            if(abs(nums[left]) > abs(nums[right]) ){
                ans[pos] = nums[left] * nums[left];
                pos--;
                left++;
            }
            else{
                ans[pos] = nums[right] * nums[right];
                pos--;
                right--;
            }
        }
        return ans;
    }
};