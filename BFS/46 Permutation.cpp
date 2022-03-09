class Solution {
public:
    void backtrack(vector<int>&input, int first, int len, vector<vector<int>>& ans){
        //back track algorithm
        if(first == len){
            ans.emplace_back(input);
        }
        for(int i=first;i<len;i++){
            swap(input[i],input[first]);
            backtrack(input,first+1,len,ans);
            //withdraw the vector
            swap(input[i],input[first]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int len = nums.size();
        backtrack(nums,0,len,ans);
        return ans;
    }
};