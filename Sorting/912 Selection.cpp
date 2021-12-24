class Solution {
public:
    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int min_index;
        for(int i=0;i<n;i++){
            min_index = i;
            for(int j=i+1;j<n;j++){
                if(nums[j]<nums[min_index]){
                    min_index = j;
                }
            }
            swap(nums[i],nums[min_index]);
        }
        return nums;
    }
};

