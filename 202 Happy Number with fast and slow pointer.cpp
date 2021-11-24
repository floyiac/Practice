class Solution {
public:
    bool isHappy(int n) {
        // fast is two iteration ahead slow.
        int fast,slow;
        slow = n;
        fast = getSum(n);
        fast = getSum(fast);
        while(fast != slow){
            slow = getSum(slow);
            fast = getSum(fast);
            fast = getSum(fast);
        }
        return (fast == 1);
    }

    int getSum(int& n ){
        int ans = 0;
        while(n){
            ans += (n%10) * (n%10);
            n = n/10;
        }
        return ans;
    }
};
