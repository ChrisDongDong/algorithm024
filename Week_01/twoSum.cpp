class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> result;
        vector<int> val(2,-1);
        for(int i = 0; i < nums.size(); i++) 
            result.insert(map<int,int>::value_type(nums[i], i));

        for(int i = 0 ; i < nums.size(); i++) {
            if ( result.count(target - nums[i]) > 0 && result[target - nums[i]] != i ) {
                val[0] = i;
                val[1] = result[target - nums[i]];
                break;
            }  
        }   
        return val;       
    }
};