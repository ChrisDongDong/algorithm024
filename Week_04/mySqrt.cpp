class Solution {
public:
    int mySqrt(int x) {
        long long s = 0, ans, mid, temp = x;
        while  (s <= temp) {
            mid = (s + temp)/ 2;
            if (mid * mid  == x) 
                return mid;
            else if (mid * mid < x) {
                s = mid + 1;
                ans = mid;
            } else  
                temp = mid - 1;
        }
        return ans;
    }
};