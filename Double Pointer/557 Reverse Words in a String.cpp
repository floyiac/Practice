class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int l=0;
        int r;
        for(int i=0;i<n+1;i++){
            if(s[i] == ' ' || s[i] == '\0'){
                r = i-1;
                while(l<=r){
                    swap(s[l],s[r]);
                    l++;
                    r--;
                }
                l = i+1;
            }
        }
        return s;
    }
};