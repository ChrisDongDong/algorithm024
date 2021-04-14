class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> uniq;
        for (char ch: s) {
            uniq[ch]++;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (uniq[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};