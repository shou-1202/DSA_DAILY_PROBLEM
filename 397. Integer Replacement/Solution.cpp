class Solution {
public:
    int helper(long n){
        if(n==1)return 0;
        n= (long)n;
        int even=1e8, odd1 = 1e8, odd2 = 1e8;
        if(n%2==0){
            even = 1+helper(n/2);
        }
        else{
            odd1 = 1+helper(n+1);
            odd2 = 1+helper(n-1);
        }
        return min(even, min(odd1, odd2));
    }
    int integerReplacement(int n) {
        n = (long)n;
        return helper(n);
    }
};