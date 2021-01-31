class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int k = 0;
        vector<int>::iterator iter;
        for (iter = nums.begin(); iter != nums.end(); ++iter) {
            if (*iter == 0) {
                iter = nums.erase(iter);
               k++;
                iter--;
                // nums.push_back(0);
            }
        }
       nums.insert(nums.end(), k, 0);
    }
};