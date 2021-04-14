class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        int right = s.length() - 1;
        while (left <= right && s[left] == ' ') ++left;

        while (left <= right && s[right] == ' ') --right;

        deque<string> dq;
        string word;

        while (left <= right) {
            char c = s[left];
            if (word.size() && c == ' ') {
                dq.push_front(move(word));
                word = "";
            } else if (c != ' ') {
                word += c;
            }
            ++left;
        }
        dq.push_front(move(word));

        string ans;
        while (!dq.empty()) {
            ans += dq.front();
            dq.pop_front();
            if (!dq.empty()) ans += ' ';
        }
        return ans;
    }
};