class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int cur = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != nums[cur]) {
				cur++;
				nums[cur] = nums[i];
			}
		}
		cur++;
		return cur;
    }
};