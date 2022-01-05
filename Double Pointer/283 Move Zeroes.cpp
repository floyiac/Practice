class Solution {
public:
    void swap(int&a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }

    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = -1; // i keeps track of the first zero element
        int j = 0; // j iterates the whole vector
        for(j;j<n;j++){
            if(nums[j] == 0){
                if(i==-1){
                    i = j;
                }
            }
            else{
                if(i==-1){

                }
                else{
                    swap(nums[i],nums[j]);
                    if(i < n-1){
                        if(nums[i+1] == 0){
                            i = i+1;
                        }
                        else{
                            i = j;
                        }
                    }
                    else{
                        i = j;
                    }
                }
            }
        }
    }
};