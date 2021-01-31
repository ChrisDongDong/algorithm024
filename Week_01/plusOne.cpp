
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int total = digits.size() - 1;
        for (int i = total; i >= 0 ; --i) {
            if (digits[i] == 9) digits[i] = 0;
            else {
                digits[i] += 1;
                return digits;
            }
        }
        // 如果全为零则前面加 1
        if (digits.front() == 0) digits.insert(digits.begin(), 1);
        return digits;
    }
};