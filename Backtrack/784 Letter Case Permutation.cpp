class Solution {
public:
    vector<string>ans;
    vector<string> letterCasePermutation(string s) {
        int len = s.size();
        traverse(s,0,len);
        return ans;
    }
    void traverse(string& s, int cur, int len){
        if(cur == len){
            ans.emplace_back(s);
            return;
        }
        if(s[cur] >= 65 && s[cur] <= 90){
            s[cur]+= 32;
            traverse(s,cur+1,len);
            s[cur]-= 32;
        }
        else if(s[cur] >= 97 && s[cur] <= 122){
            s[cur]-=32;
            traverse(s,cur+1,len);
            s[cur]+=32;
        }
        traverse(s,cur+1,len);
    }
};

