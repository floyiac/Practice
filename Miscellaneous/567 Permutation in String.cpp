class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if(len1 > len2){
            return false;
        }
        vector<int> a(26);
        vector<int> b(26);
        for(int i=0;i<len1;i++){
            ++a[s1[i] - 'a'];
            ++b[s2[i] - 'a'];
        }
        if(a == b){
            return true;
        }
        for(int i=len1;i<len2;i++){
            --b[s2[i-len1] - 'a'];
            ++b[s2[i] - 'a'];
            if(a == b){
                return true;
            }
        }
        return false;
    }
};

