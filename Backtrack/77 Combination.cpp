class Solution {
public:
    vector<vector<int>>ans;
    vector<int> temp;
    vector<vector<int>> combine(int n, int k) {
        recursion(1,n,k);
        return ans;
    }
    void recursion(int cur, int n, int k){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        if(temp.size() + n - cur + 1 < k){
            return;
        }
        temp.emplace_back(cur);
        recursion(cur+1,n,k);
        temp.pop_back();
        recursion(cur+1,n,k);
    }
};