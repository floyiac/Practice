class Solution {
public:
    bool isHappy(int n) {
        //要判断是否一个数出现，可以考虑哈希表
        unordered_set<int> hashmap;
        while(hashmap.find(n) == hashmap.end()){
            hashmap.emplace(n);
            n = getsum(n);
        }
        return n==1;
    }

    int getsum(int n){
        //Trick: 提取一个数的各个位数
        long int sum = 0;
        while(n){
            sum += (n%10) * (n%10);
            n = n / 10;
        }
        return sum;
    }
};