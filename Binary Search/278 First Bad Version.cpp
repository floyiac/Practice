// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while(left <= right){
            int middle  = left + (right - left) / 2;
            if(isBadVersion(middle)){
                right = middle - 1;
            }
            else{
                left = middle + 1;
            }
        }
        return left;
    }
};