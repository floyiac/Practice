class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        if(nums[right] < target){
            return right + 1;
        }
        if(nums[left] > target){
            return left;
        }
        while(left <= right){
            int middle = left + (right - left) / 2;
            if(nums[middle] == target){
                return middle;
            }
            else if(nums[middle] < target){
                left = middle + 1;
            }
            else if(nums[middle] > target){
                right = middle - 1;
            }
        }
        return left;
    }
};